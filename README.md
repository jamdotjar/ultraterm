# ULTRATERM
![Hero image](gallery/key_preview.png)
- A 2000mAh battery
- Bluetooth headphone support
- USB-C storage interface
- Removable SD card storage ( and a custom microSD card adapter )
The case is designed to be entirely 3D printable, and assembled without adhesive or fasteners.
While the terminal isn't a perfect replica, it's decently close. ( for example, there's none of the wires near the top, but there is a magnetic attachment point so I *can* add them )

This project was made as mostly a fun intro to custom hardware. I've made keyboards before, but design wise those are fairly simplec ( this isn't much more complicated ). I decided to shape it after the ULTRAKILL Cybergrind terminal because that's the one that handles  cybergrind music ingame, so I thought that would be a cool part to try and recreate. Even though it isn't *the* classic terminal, its form factor is also a *lot* more forgiving to fit a screen and PCB and stuff into when compared to the shop terminals, which also don't have as many good options for physical interface. 

If you happen to make your own, I'd suggest either 3d-printing it in blue for minimum effort, or printing it in grey, painting it, then scuffing the paint to give it the worn look it has in-game. 

## Gallery


![ULTRATERM back IO render product render on black background](gallery/bl-back.png)
![ULTRATERM cutaway](gallery/cutaway.PNG)
![ULTRATERM product render in ULTRAKILL enviroment](gallery/header.png)
![ULTRATERM left angle product render on black background](gallery/bl-ang-left.png)
*more in [./gallery](gallery)*

## PCB
<img width="875" alt="image" src="https://github.com/user-attachments/assets/9fd5e89d-9d3f-4c49-aeb6-2983ae4dbfe5" />
<img width="400" alt="Screenshot 2025-07-03 at 11 37 43 PM" src="https://github.com/user-attachments/assets/2922b129-de5d-4397-ad61-25974096de33" />
<img width="400" alt="Screenshot 2025-07-03 at 11 37 01 PM" src="https://github.com/user-attachments/assets/cc42b526-2fa3-4005-8990-93430f955d95" />
<img width="700" alt="image" src="https://github.com/user-attachments/assets/86971548-41dc-4e53-9309-176ed50dba61" />


## Case
<img width="380" alt="Screenshot 2025-07-03 at 11 41 00 PM" src="https://github.com/user-attachments/assets/c7ed8e2f-58ae-4164-a7fb-76fb8261c662" />
<img width="380" alt="Screenshot 2025-07-03 at 11 40 50 PM" src="https://github.com/user-attachments/assets/8aa4eb87-1eaa-4392-a68d-9a0aa4ad6cea" />

<img width="380" alt="Screenshot 2025-07-03 at 11 45 09 PM" src="https://github.com/user-attachments/assets/552af0e2-f642-4052-b81a-d14f586bfd60" />
<img width="380" alt="Screenshot 2025-07-03 at 11 44 03 PM" src="https://github.com/user-attachments/assets/f08572af-d590-4923-b969-a47b4e9e34b6" />

## BOM 
*prices in usd*
| Item | Quantity | Price | Supplier | Notes |
| --------------- | --------------- | --------------- | --------------- | --------------- |
| PCB | 5 | 4.7 | JLCPCB | |
| TINYPICO v2 | 1 | 39.5| Digikey | 29.41 + 10.00 shipping ( better than other places charging 20+ 25)|
|TZT 240x320 2.8" SPI ST7789V LCD Touch Panel | 1 | 7.09 | Aliexpress | |
| 3.7v 2000mah LiPo battery | 1 | 16.92 | Amazon | price comparable to ali, with substantially faster shipping options |
| Pin Headers | 20 | 2.00 | Aliexpress | for stupid LCD mounting soln. |
| 22Awg wire | 5m | 2.4 | Aliexpress | front panel mount + battery backup soln. |
| 32gb microSD card |1 | 4.7 | LCSC | | 
| 32gb SD card|1 | 5.8 | LCSC | |
| LM809 | 1 | 0.66 | LCSC | | 
| JST-PH-2 | 10 | 0.59 | LCSC | |
| SPDT slide switch | 20 | 0.48  | LCSC | |
| 6mm pushbutton | 50 | 0.84 | LCSC | |
| Amphenol 10067847-001RLF | 1 | 1.31 | LCSC | |
| Hirose C719027 | 1| 1.04 | LCSC |
| LCSC Shipping || 12.88  | LCSC | | 
| Total | 1 |  95.21| | |  
## Assembly

*we'll see how this goes once I get the parts in*

## LICENSE

This project uses the [CC-BY-SA-4.0](https://creativecommons.org/licenses/by-sa/4.0/) for all firmware, documentation, renders, and other writing. Hardware including all Case and PCB designs, is licensed under the [CERN-OHL-W v2](https://ohwr.org/cern_ohl_w_v2.txt)
> This project was heavily inspired by the game ULTRAKILL, created by Hakita (Arsi "Hakita" Patala). The ULTRATERM design, as well as some assets used in renders are derived from or inspired by ULTRAKILL.
All rights to ULTRAKILL belong to Hakita and New Blood Interactive. This project is not affiliated with or endorsed by Hakita or New Blood. 
( [ULTRAKILL is a banger game, you should totally get it, it's like 20 bucks ](http://devilmayquake.com))

This project was made for [*highway*](https://highway.hackclub.com)
