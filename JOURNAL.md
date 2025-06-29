---
title: "Ultraterm"
author: "Finn H"
description: "A replica of the ULTRAKILL cybergrind terminal ( it plays music! )"
created_at: "2025-05-19"
---

# Journal
### 2025/05/19 ( and the past 3 days I didnt )
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
