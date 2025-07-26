---
title: "ULTRATERM"
author: "Finn H"
description: "A bluetooth MP3 player styled as a miniature replica of the ULTRAKILL cybergrind terminal"
created_at: "2025-05-19"
---

# ULTRATERM Journal

> *time spent up to when this was last changed: 60hrs*

### 2025/05/19 ( and the past 3 days I didnt journal )
This has been mostly just research on *how* I'm actually pulling this off. I've ( tenatively ) setteled on this as a **very rough** list of what I'll use:
- ESP32s3
- Some sort of small TFT display
- microSd reader
- rotary encoder?
- headphone jack
- some buttons ?
- rechargeable battery?
I still need to figure out the best input methods, as well as whether a battery is super important for the design. I think it would be a nice bonus, but not nessicary if the footprint gets too tight.
I also started to gather references for the design, not sure whether to go for the pre or post revamp termial model for inspo. ( these frickers )

![image](https://github.com/user-attachments/assets/4f8d5219-77a8-42c2-8673-bb289b055284)
![image](https://github.com/user-attachments/assets/c2f69cd9-6f2b-4f7f-beb8-82d3f28069b1)

Scraped ultrakill assets for raw files, need to actually find the terminal now

<img width="630" alt="image" src="https://github.com/user-attachments/assets/b6524f30-26d6-41a4-967d-a6756dfacd0a" />

> *time spent: ~4 hrs over the last 3 days?*

### 2025/06/04
OK, so it's been a while. I kinda dissapeared so i could speedrun solder, and resign my hackboard case to practice CAD. 
I've semi-settled on a ~2.4 inch display~, it didnt fit, so I'm starting to design the case based off of it. It was a pain to scrape the ultrakill models, but I'm in love with the design of the cybergrind terminal, ( there's a section on the back that's just begging for a SD card slot :3 )

<img width="351" alt="image" src="https://github.com/user-attachments/assets/e31413df-4f7e-42ea-bb0e-e0c0569f584e" />

The basic case shapes are done, so I'm going to start to try laying out part locations, and then I'll get on the PCB! I changed to a 2.8 inch display ( A  ILI9341 ), so I can finalize a parts list around that now!

<img width="282" alt="image" src="https://github.com/user-attachments/assets/10fd5ce8-799a-46fc-939c-b3ef852cb643" />

> *time spent: 3 hrs*

### 2025/06/21 
Ahhhhhhh, there was so much to do. Now I guess I have to speedrun this in two weeks.
ESP32 variant changed to a SEEED Xaoi esp32s3 for the smaller form factor, and builtin battery charging. 
The final parts list is
- XAIO Esp32s3
- ILI9341 2.9 inch TFT display
- [2k mAH liPo](https://www.aliexpress.com/item/1005008129110763.html?aem_p4p_detail=202506221800583223276838451580005928444&algo_exp_id=9986c4f7-9e79-42c7-89a9-f8e37e361f89-7&pdp_ext_f=%7B%22order%22%3A%22640%22%2C%22eval%22%3A%221%22%7D&pdp_npi=4%40dis!CAD!18.58!1.39!!!95.19!7.12!%402103205117506404581112585e1741!12000043904507912!sea!CA!6379572868!ABX&curPageLogUid=IeYcnJN452sK&utparam-url=scene%3Asearch%7Cquery_from%3A&search_p4p_id=202506221800583223276838451580005928444_2)
- JST PH 2.0 socket
- 3 buttons ( idk what kind will fit yet )
- MicroSD card reader
- TRRS jack
I also figured out that there's a very convenient little notch on the back where all of the io fits perfectly, which I'm very happy about, although it does make me a little scared about how big this will actually be

<img width="570" alt="image" src="https://github.com/user-attachments/assets/f15ded9c-4c46-4d10-a776-3f2b9c0b5eee" />

I've dumped all of the parts into kicad so now I just need to figure out how to actually connect it to the MCU, I'm slightly worried about the limited pin count, i might need to cut the TRRS jack, but I'm not too invested in that.

<img width="595" alt="image" src="https://github.com/user-attachments/assets/b5280801-0c0b-44a4-8bb3-b2bfa5ff7d60" />


> * time spent: 2hrs*

### 2025/06/25
Picking up from where I was last time, i'm trying to figure out how to interface with the SD card in SPI mode so I'm reading through the specifications for that. Also debating whether a touchscreen would be better. It is more lore accurate, and it might make interfacing easier, but I'm not sure if the cost/complexity overhead is worth it. I'll look into it more after the microSD card bit is done. 
After about an hour of bashing my head against the wall, it turns out the SD card can be wired directly to my MCU... fun. 
The schematic is finished, the display has changed once again to a model with basic resistive touch. At worst it's a dollar or so more expensive, and at best UX is a lot easier to design.
Ther schematic so far:

<img width="381" alt="image" src="https://github.com/user-attachments/assets/8b4c0721-0660-4fb5-86cf-093755cdfab8" />

I'm curretntly really far into trying to figure out how to wire the reset pin to power so it automatically resets when the device turns on, finally figured out I just needed a LM809

<img width="283" alt="image" src="https://github.com/user-attachments/assets/533193e1-a5b7-4feb-baed-df708970530a" />

Now for PCB, The main thing is making all the IO line up with the bottom port, and having the screen be in roughly the right spot as well. The front buttons will probably need to be a seperate PCB somehow. From my estimations in fusion, there will be a 36mm gap between the bottom of the LCD and the bottom of the IO, which *should* be enough to fit everything.

> *time spent: 4hrs 😭*

### 2025/06/26
I'm trying to figure out the PCB layout, the three main  struggles are how to connect the buttons, where the power switch goes, and how to get the IO to fit in it's slot. 

Some finagiling later I've decided that I'm just leaving a really thin little spindle to get the display connector, and then use the blank space for a seperate button plate, and potentially a microsd card adapter. This is what the layout looks like *so* far, hopefully I dont need many changes for routing. I'm mainly trying to keep this under the 100x100mm jlcpcb cheap factor.

<img width="686" alt="image" src="https://github.com/user-attachments/assets/27c0af24-9a46-49e0-a1b6-7860d67e8727" />

> *time spent: 3hrs*

### 2025/06/27
The PCB had a bit of extra room near the top, so I added a small microSD to SD card adapter. Mainly a convenience thing, so I can use both, and this way I can put whatever silkscreen I want on it.

<img width="364" alt="image" src="https://github.com/user-attachments/assets/4f5d33f9-e619-4590-a979-9d5006dab554" />

The board is structurally complete, and fully panelized, now I just need to figure out how to fit everything into the case. Something tells me mounting these is going to be a bit of a pain. (ignore the blue sc card reader)

<img width="949" alt="image" src="https://github.com/user-attachments/assets/e0d9433e-6f53-4ea7-b5d9-0c417bebddc7" />

PCB is done though, so i'm happy abt that. 
Never mind. I forgot the orginal was desinged around a 2._8_ inch screen, so now the positioning is all off. Time to go fix that, yayyyyy.
The midnight grind session has brought many fruits. first, I found a suitable display replacement on aliexpress. Most displays had the pins below the holes, but I needed one with them between them so it would fit in the case ( from rough estimations ).

<img width="208" alt="image" src="https://github.com/user-attachments/assets/7f47381c-aff8-4346-9d31-327be09d5915" />
<img width="213" alt="image" src="https://github.com/user-attachments/assets/8e5d9753-61df-46d0-8de8-c24e62a628c5" />


After making a new footprint, remeasuring my case, and moving it on the PBC. It took a while to reroute the extra pins, but I'm confident it'll be for the last time. 

<img width="635" alt="image" src="https://github.com/user-attachments/assets/9272b2d7-523d-4be1-8a4b-2a8a64df5834" />

> *time spent: 6hrs*
### 2025/06/08
I brought the PCB into cad to check the dimensions one final time. 

Aaaand, kicad is refusing to export my step files with 3d component models. All it's exprorting now is the fricking SD card slot, I have 0 clue why ( it worked fine an hour ago, which is how long i've been trying to fix this stupid problem )
I still don't know why it wasn't working, but I added the missing components in fusion, so it's fine now. 
After a bit of fiddling, here's it all laid out. 

<img width="256" alt="image" src="https://github.com/user-attachments/assets/5b3ceb98-2d32-4dda-bd78-918f514ef7c4" />
<img width="256" alt="image" src="https://github.com/user-attachments/assets/522c6a86-155e-4174-b552-781d42828e42" />

The next step is to make the solid block the case currently is into a proper shell, and add some things to help mount the PCB. I started by removing the surface details that would need to be cut out, and then I made the main case into a shell. To determine the wall thickness, I was having a tough time actually visualizing *how* each thickness would fare, so I printed out some samples for 1, 2 and 3mm.
![testcubes](https://github.com/user-attachments/assets/05700fad-1064-4e38-b311-9c70b9f8da31)
As expected, 1 suffered from flimsiness and light bleed. 3 was close to what I needed, but it was just a touch thick so I went with 2.5mm. This was half an hour for a decision between three numbers, I might need to reprioritize where I'm spending my time.

Given I need to actually assemble this case, my main concern is how I'll split the body so it can go together in a somewhat reasonable manner. I  sketched up a few different options, trying to get a sense fro how to hide seams, while keeping it fairly easy to assemble.

In the end, it makes the the most sense to me to cut it horizontally, similar to the blue line. (as well as potentially letting the bottom come off)

<img width="348" alt="image" src="https://github.com/user-attachments/assets/a3468dda-b0fd-48a2-9a0e-67df79bf61dc">
<img width="348" alt="image" src="https://github.com/user-attachments/assets/338f9647-5d16-47e4-9386-d929c028c92d">

wrangling with fusion made today a bit of a slow day. I'm hoping to finish the case over the next two days, so I can whip up a rough version of the firmware, and polish the project for shipping. 

> *time spent: 4hrs*

### 2025/06/29

Most of today's work was solely focused on making a decent case in fusion. I spent way too long trying to figure out how to actually split the shell as I'd planned, and the initial split was really janky, which required a bit of clean-up, but now everything looks good.
<img width="526" alt="image" src="https://github.com/user-attachments/assets/3b96eff5-bf60-4598-b5d6-4dd859aff559" />

My biggest problem with the case is making sure that A: it looks at least *somewhat* like the real deal. B: The parts actually fit inside, and stay where they're supposed to.

Scraping the game files for a reference back on the very first day mostly dealt with the accuracy concenrns ( hopefully my paint skiolls will be able to patch up the rest — wait, crap, skills. hmm, maybe I'll just get some blue filament )

As for the parts fitting, I have *no clue* how that's gonna work. I know where they need to be, and while just supergluing them in, or encasing the entire thing in resin might *seem* convenient. I have a sneaking suspicion that that is a terrible idea, so I spent way to long thinking before I realized I can just use snap tabs. 

<img width="375" alt="image" src="https://github.com/user-attachments/assets/789b5ba0-fc13-4d57-8acd-ab6669ec18dc" />

After modeling them, I realized that they were clipping out of the back of the case, and proceeded to go mad trying to fix it. 
The above sentence was written before I tried to do that, after writing, I did it wrong, second guessed myself, and wasted 30 minutes trying objectively worse solutions. Moral of the story is trust your gut or something I guess.

<img width="227" alt="image" src="https://github.com/user-attachments/assets/92fa8a46-9633-4134-a40d-3d4a74d2e083" />

In other news for today, I added the IO cutouts, I grill on the back I missed for some reason, and a screen cutout 

<img width="400" alt="image" src="https://github.com/user-attachments/assets/92a72ca8-8d4d-4029-afa3-ba4ce0f09d7a" />
<img width="400" alt="image" src="https://github.com/user-attachments/assets/68e89be0-6162-4636-ad72-5be1bdabd8ea" />

> *time spent: 4hrs*

### 2025/06/30

After (sorta) figuring out mounting for the PCBs yesterday, I spent most of today adding mounting points for the screen, button panel, and battery ( which I kinda forgot existed until now ). I'd initially planned for the battery to be 2000 mAh for no reason at all, so I had to double check the expected battery life. I estimate the system will have a power draw of roughly 200mA, meaking the *ideal* battery life would be around 10 hours of constant use, which is totally fine by me. Worst comes to worst, the battery can just be swapped out, because I included a standard JST 2.0mm connector 👍

I also added more snap-fit connectors to the case itself, so it can actually fit together ( and come apart ) all without any fasteners, which was one of my goals from the begininning.
Once that was done, I finished by adding in all the details I forgot to model earlier, all the little slots, panels, and other sci-fi greebles. Anyways, since most of the changes were just small modelling changes, here's a screenshot dump:

<img width="320" alt="image" src="https://github.com/user-attachments/assets/71256c3a-5af3-481f-add4-fec1a95736f4" />
<img width="513" alt="image" src="https://github.com/user-attachments/assets/394b4bec-63ec-4a9f-bb14-8afe95d767ce" />
<img width="192" alt="image" src="https://github.com/user-attachments/assets/b5003a0f-e961-4699-8f29-e21fe99fae96" />
<img width="152" alt="image" src="https://github.com/user-attachments/assets/d9e5f061-5070-40ce-8add-c21eb8d9489e" />
<img width="429" alt="image" src="https://github.com/user-attachments/assets/64927230-0c94-46b4-a45f-fee311b5635f" />
<img width="122" alt="image" src="https://github.com/user-attachments/assets/b8323f6f-28a2-44eb-8009-8976893f00f5" />
<img width="152" alt="image" src="https://github.com/user-attachments/assets/3a917478-0483-4f9a-a298-db79d7091dfc" />
<img width="344" alt="image" src="https://github.com/user-attachments/assets/ef40a70e-6ccf-478f-81ee-0b01f238f150" />
<img width="274" alt="image" src="https://github.com/user-attachments/assets/3255185a-7613-4b2d-adce-b9573e1aa479" />
<img width="274" alt="image" src="https://github.com/user-attachments/assets/460f8bac-c688-4f05-b816-cbe695a30528" />
<img width="534" alt="image" src="https://github.com/user-attachments/assets/39140b68-2eeb-4f26-a087-e66e5fd37e8f" />

With that, I'd say the case is actually complete, leaving me ( technically ) 2/3 of the way through this process. The last step is a basic firmware, which only needs to do 3 things.
1. Connect to bluetooth headphones
2. Read and playback from the SD card
3. Display controls for the above onscreen
Once that's all done my stretch goals are to:
- make it look as game accurate as possible
- Let people upload files to the device either wirelessly, or when plugged in.

> *time spent: 4hrs*

### 2025/07/01
I started trying to get some sort of firmware made today. The first step was trying to figure out *how* to go about embedded firmware. A bit of googling led me to PlatformIO which seemed simple enough, while still giving me a fair amount of control. Luckily, I had an esp32s3 devboard lying around, so I can actually test at least part of my code. ( The bluetooth function, specifically and maybe the SD card if I'm feeling like soldering to the pads of one ). As of right now, I have uploaded some test code, but not much past that. 

I took a bit of a break to make my BOM, because I'm pretty confident with the physical design at this point. Unfortunately, I did have to go back and edit my PCB as the SD card connecter I had chosed turns out to be discontinued.
It also turns out the power switch I was using was not a toggle switch, so now I need to find one of those, and figure out where the hell to put it. So, uh, yeah. Awesome day, I've gone backwards. I needed to remodel the case to fit the new switch, so I guess I'll finish the BOM tomorrow, and speedrun some firmware.
<img width="199" alt="image" src="https://github.com/user-attachments/assets/d9f14811-e6f9-4e51-86fa-9542e78b7e22" />


> time spent: 3hrs*

### 2025/07/02

I finished the BOM today, which took a bit longer than I expected. Still, it's anothers step towards this being complete so I'm not too pressed about it. After the BOM, I jumped back into the firmware. My main goal for a hopepfully functional MVP is to connect to headphones, play audio to them, and have a button to like, shuffle or something. 

SHIT, the esp32s3 doesn't support A2dp, so now I need a completely differnt chip, that'll be in a different form factor. yay. 
why do things keep going wrong. ( granted, I should have researched better, but I thought the s3 would work ). 

I found a suitable replacement board, the TinyPico. It it a fair bit more expensive, but I'm under budget so I think it's fine. ( also, the other board would have required me to get a hotplate, which would have been an additional $20 anyways ) after a lot of checking, it has everything I need:
- Battery management
- USBC
- Small footprint
- Bluetooth A2DP
So that is now the core MCU, it's based on the esp32-pico d4, and it's going to do a great job. There are no avalable footprints or symbols, so I had to make those, which was a bit of a pain. One good thing to come out of this is that there was a spare few pins, so I was able to add a status indicator LED, something i've wanted to do for a bit. So, at least there was *a singular upside* to today.

<img width="206" alt="image" src="https://github.com/user-attachments/assets/762f2767-f8fa-41f5-a0cd-91c244ed91ee" />

I made a footprint, and completely rerouted my PCB. I kept the USB in the same spot, so the case design *should* still work 🙏. Now to hop back to firmware :yay:
> *time spent: six. hours. why. ( update, I worked more so it's actualy like 8 (
> <img width="32" alt="image" src="https://github.com/user-attachments/assets/2893fa1a-da55-4c61-8477-e8c39727095e" /> )

### 2025/07/03

After yesterday's fiasco, I am right back where I was before it all went pear shaped. So, firmware... take two ( with the slight downside that I can't actually test my code now ). 
To start, I tried to figure out what my priorities would be for the first rough draft of my code. After a touch of thinking, I decided on the order of:
- Headphone pairing
- Audio playback
- SD card reading
- Button input
- UI display
- Touch input
- Mass storage device
For this, I'm mostly focusing on the first two for the prototype, then once I get the actual device and can test the rest of the functions, I'll do that.
As for an actual application flow, I think
1. bluetooth pairing
2. Main menu ( shows info )
3. Playback
seems reasonable. I'll probably use LVGL for UI if I get there.

I started off with the bluetooth. I managed to find a library that implemented A2DP audio source for arduino, that also seems to handle the connection logic for devices, so I was ablle to get a simple version of that all set up ( it just tries to pair to the first device it sees, maybe a bit of room for refinement in the future. From there, I started with file reading, to actually provide the audio stream. 

After that, the main goal was to get some sort of interaction and input going. ( and maaaybe some output ). 

> * time spent: 3hrs*

### 2025/07/04

I'm getting pretty close to finishing this, I can feel it. I spent a bit of time last night polishing up the README, so now all I'll need to do is add some nice renders, finish this firmware, and I'm done!

I hopped back into my firmware with the input management, and I got through the first half of a callback system, that should be OK for the buttons. I think the touch might need a seperate handler once I've gotten LVGL running, but in the meantime I've just set it as another "button".

I also had to go and fix some of the storage code, because I'd used the wrong library example as a base, so had to redo the PCM stuff. Now I'm going back to input, and as a last goal I'll try to get a simple state display runnning. I actually think all of my input and playback should work! It all at least compiles, which gives me a fair bit of hope. 

Now for some actual interaction, then I can whip up a 'lil demo UI! I don't want to attempt the final UI until the final version, but it's close! 

I added a basic interaction system, that took way longer than anticipated due to having to handle my multi-core concept of having one handle playback and the other handling input and UI to let both run smoothly. It turns out i forgot how hard communicating between cores is, so I had to use a input queue to handle the audio via button presses, and now I have a basic UI that displays the current playback state.

For my last change to the protoUI, I converted the VCR_OSD_MONO font from ultrakil to LVGL C, so I can use it as the main font for my UI.

Tomorrow goals are to polish the demo UI, README, and CAD to make sure everything is ready for submission ( and hopefully submit too ), after that, there will likely be some more work on the final UI. I think LVGL lets you preview the UI somehow so I'll look into that, because anything I can prototype before I get my parts is good. Once I do get my parts, I'll also journal the assembly, and road to a physical v1, so stay tuned.

> *time spent: 3hrs*

### 2025/07/05
<img width="1028" alt="image" src="https://github.com/user-attachments/assets/8fa993c0-1528-4e55-84e6-4c6d61234d58" />
*sucess*
I was busy most of today, but I did manage to get my firmware to compile in the state I want it to which at this point is my only real metric for whether or not it will work. Once I was happy with that, I turned my attention back towards the readme, as I wanted some images to put in the gallery. I needed some simple renders in blender, showing what the whole thing might look like. I also wanted one, more stylized "header" image to go right at the top. I didn't have a photo of the in-game terminal anywhere in the readme so far, so including it in this seemed like a good idea. Since this would be *the* headliner image, I decided to actually give it an ounce of planning.  What I managed to come up with was a scene where it's split between the original terminal and my version, in their respective enviroments. ( hell and desk ). 
I started by importing my terminal into blender, and setting up a material. I decided to try and mimic the texture of a 3d print, which lead to this node setup:
<img width="1470" alt="image" src="https://github.com/user-attachments/assets/9687a8e9-9208-4a3f-b50a-90be7e9104e4" />
Then I pulled in the actual terminal model ( thanks again to me for scraping it back in may ), and promptly had to go digging around the unity project anyways to find the elevator model. Unity happend to lose every single texture, so I had to resort to the somehwat outdated model collection I found online.

Either way, that got me the entrance area, and let me finally finish setting up my scenes. Yay. On the bright side, I'm actually almost done for real this time™ 

As a last ditch effort for "today" I finished the two component renders for the header. Tomorrow I can do the differnt angles of the main device. 
![image](https://github.com/user-attachments/assets/deadc612-c06f-4633-b0ef-7f057845fa1b)
![image](https://github.com/user-attachments/assets/348a694f-bd0e-423b-81a8-635d045b20f0)

> *time spent: 4hrs*

### 2025/07/06
Right back into blender today, I spent the morning working on a few more renders. *they're different, trust*
![image](https://github.com/user-attachments/assets/5c40f58e-93f5-4824-87b6-0170f561740e)
![image](https://github.com/user-attachments/assets/07931fa0-85d6-4eb3-93fe-fce6422c12e0)

After I was good with the hell reners, I popped back into my void to get some "product photos". I had to adjust the lighting on the blackvoid renders, as it was way too harsh before, so I just went back to a basic 3 point lighting setup.

I just spent the last 4 hours on renders, here's the rest of what I did!
![image](https://github.com/user-attachments/assets/0c2763c0-bf83-46dc-a4e3-320362d153f7)
![image](https://github.com/user-attachments/assets/53fddfd7-799c-4390-9113-db08df8f2975)
![image](https://github.com/user-attachments/assets/976a2321-bda4-421f-a562-76bde7e03f08)
![image](https://github.com/user-attachments/assets/05f9f6b3-7ee4-4262-a1bd-9a390902747b)

After that, I took the images and tried to combine some together to get a header, and a cutaway view. I also updated the README with Lisences and other legal stuff, and added a lil highway link. I'll add a less little one here, because if you're reading *this* you definitely care enough to check out Hack Club. 

![A badge of a Cerberus and a raccoon laughing together, with the text "HIGHWAY" and "HACK CLUB" beside them.](https://hc-cdn.hel1.your-objectstorage.com/s/v3/0bbcca68ffa3845300bb76940f8ad91fd53d2d68_06-30-2025-1618.png)

I'm going to ask for some feedback from friends, then I'll submit!

> *time spent: 5hrs*

## 2025/07/20
Another big break, but this time because I went to Undercity. 10/10 experience lol. In the time since then, I've printed out my case, and everything fits. I still need to paint it, but it should be good to go as soon as I get the rest of the parts. Speaking of the rest of the parts, my grant came in today so I could finally start ordering everything. I did, but not before plastering the PCBs with some decoration! 

<img width="404" height="469" alt="image" src="https://github.com/user-attachments/assets/bd0d71c9-c8d6-4840-aecb-ab1461fa85f1" />
<img width="482" height="504" alt="image" src="https://github.com/user-attachments/assets/5cb35998-c5fe-4331-8cb8-595bd073cc26" />

> *time spent: 2hrs*



