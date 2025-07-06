#include <Arduino.h>
#include <SD.h>
#include <FS.h>
#include <vector>
#include <string>
#include "MP3DecoderHelix.h"
#include "storage/storage.h"

using namespace libhelix;

// Audio processing components
MP3DecoderHelix decoder;
File currentFile;
bool fileOpen = false;

// Buffer for decoded audio data
int16_t audioBuffer[2048];  // Changed to int16_t for PCM data
int bufferPos = 0;
int bufferSize = 0;

// Circular buffer for storing decoded PCM data
int16_t pcmBuffer[4096];
volatile int pcmWritePos = 0;
volatile int pcmReadPos = 0;
volatile int pcmAvailable = 0;

//pauseplay crap ( please work )
size_t pause_position = 0;
bool paused = false;

// Callback function for MP3 decoder
void dataCallback(MP3FrameInfo &info, int16_t *pcm_data, size_t len, void* ref) {
    // Store decoded PCM data in circular buffer
    for (size_t i = 0; i < len; i++) {
        if (pcmAvailable < sizeof(pcmBuffer) / sizeof(int16_t)) {
            pcmBuffer[pcmWritePos] = pcm_data[i];
            pcmWritePos = (pcmWritePos + 1) % (sizeof(pcmBuffer) / sizeof(int16_t));
            pcmAvailable++;
        }
    }
}

bool storage_init(size_t CS_PIN) {
    Serial.println("Initializing SD card...");
    
    if (!SD.begin(CS_PIN)) { 
        Serial.println("SD card initialization failed!");
        return false;
    }
    
    Serial.println("SD card initialized successfully");
    
    // Set up the callback and initialize decoder
    decoder.setDataCallback(dataCallback);
    decoder.begin();
    
    return true;
}

std::vector<std::string> get_songs() {
    std::vector<std::string> mp3Files;
    
    File root = SD.open("/");
    if (!root) {
        Serial.println("Failed to open root, might be an FS problem"); //my best guess at why
        return mp3Files;
    }
    
    File file = root.openNextFile();
    while (file) {
            std::string filename = file.name();
            // Check if file has .mp3 extension
            if (filename.length() > 4 && 
                filename.substr(filename.length() - 4) == ".mp3") {
                mp3Files.push_back(filename);
                Serial.println(filename.c_str());
            }
        file = root.openNextFile();
    }
    
    root.close();
    return mp3Files;
}

bool open_mp3_file(const std::string& filename) {
    if (fileOpen) {
        close_mp3_file();
    }
    
    currentFile = SD.open(("/" + filename).c_str());
    if (!currentFile) {
        Serial.printf("Failed to open %s\n", filename.c_str());
        return false;
    }
    
    fileOpen = true;
    bufferPos = 0;
    bufferSize = 0;
    paused = false;
    pause_position = 0; // reset pause pos
    
    // Reset PCM buffer
    pcmWritePos = 0;
    pcmReadPos = 0;
    pcmAvailable = 0;
    
    // Restart decoder for new file
    decoder.begin();

    Serial.printf("Opened %s\n", filename.c_str());
    return true;
}

void close_mp3_file() {
    if (fileOpen) {
        currentFile.close();
        fileOpen = false;
        paused = false;
        pause_position = 0; // reset pause pos
    }
}

void pause_stream() {
    if (fileOpen) {
        paused = true;
        pause_position = currentFile.position(); // Save current position
        fileOpen = false;
        Serial.println("paused");
    }
    else {
        Serial.println("could not pause, no file");
    }
}
void resume_stream() {
    if (fileOpen) {
            currentFile.seek(pause_position); // Resume from saved position
            paused = false;
            fileOpen = true;
            Serial.println("resumed");
    }
    else {
        Serial.println("could not resume");
    }
}
bool is_paused() {
    return paused;
}
bool is_playing() {
    return fileOpen;
}

void seek_to(size_t position) {
    if (fileOpen) {
        currentFile.seek(position);
        bufferPos = 0; // Reset buffer position
        bufferSize = 0; // Reset buffer size
        
        // Reset PCM & decoder
        pcmWritePos = 0;
        pcmReadPos = 0;
        pcmAvailable = 0;
        decoder.begin();
        
        if (paused) {
            pause_position = position;
        }
        Serial.printf("playback position set to: %zu\n", position);
    } else {
        Serial.println("no file open");
    }
}

int32_t get_stream(uint8_t *data, int32_t bytes) {
    if (!fileOpen) {
        memset(data, 0, bytes);
        return bytes;
    }
    
    int32_t totalBytesRead = 0;
    int16_t* output = (int16_t*)data;
    int32_t samplesNeeded = bytes / sizeof(int16_t);
    
    while (totalBytesRead < samplesNeeded) {
        // if no audio, read more 👍
        if (pcmAvailable == 0) {
            uint8_t mp3Buffer[512];
            int mp3BytesRead = currentFile.read(mp3Buffer, sizeof(mp3Buffer));
            
            if (mp3BytesRead == 0) {
                // End of file reached, fill remaining with silence
                while (totalBytesRead < samplesNeeded) {
                    output[totalBytesRead++] = 0;
                }
                return bytes;
            }
            
            // Feed MP3 data to decoder (this will trigger the callback)
            decoder.write(mp3Buffer, mp3BytesRead);
            
            // If still no PCM data available, continue reading
            if (pcmAvailable == 0) {
                continue;
            }
        }
        
        // Copy PCM data to output buffer
        int samplesToCopy = min(samplesNeeded - totalBytesRead, (int32_t)pcmAvailable); //holy crap this is a weird fix
        for (int i = 0; i < samplesToCopy; i++) {
            output[totalBytesRead++] = pcmBuffer[pcmReadPos];
            pcmReadPos = (pcmReadPos + 1) % (sizeof(pcmBuffer) / sizeof(int16_t));
            pcmAvailable--;
        }
    }
    
    return bytes;
}