#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <string>

bool storage_init(size_t CS_PIN);
std::vector<std::string> get_mp3_files();
bool open_mp3_file(const std::string& filename);
void close_mp3_file();
int32_t get_stream(uint8_t *data, int32_t bytes);
void pause_stream();
void resume_stream();
bool is_paused();
void seek_to(size_t position);

#endif // STORAGE_H
