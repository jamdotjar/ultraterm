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

> *time spent: 3 hrs
