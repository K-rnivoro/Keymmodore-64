<img width="1200" height="150" alt="KEYmmodore_64-3" src="https://github.com/user-attachments/assets/27513dbf-624a-4bcf-a6cf-d66e24ab118c" />

## An interface for converting a Commodore-64 Keyboard to USB, compatible with any Operative System, and VIC-20, C-64, C-128, Plus/4 and PET emulators.

The Keymmodore-64 project is a hardware interface to convert keyboards and joysticks of Commodore C-64 computer, in a USB (HID) device, able to be connected to any "Host" computer or device, like: PC (Windows/Linux), Raspberry Pi, Mac, or even Android. Therefore, the keyboard works like any other keyboard, optionally you can connect old Atari-like joysticks and their inputs would be translated to keystrokes too.

In order to make a C-64 keyboard productive for a PC, Keymmodore-64 includes a lot of key combinations, like using the Commodore key as Function Key. This way, your C-64 Keyboard includes almost all keys you need for your everyday work.

Besides the standard "PC Mode", Keymmodore-64 also includes five modes optimized for all 8 bit Commodore Computers emulators, like [VICE](https://vice-emu.sourceforge.io/) or the excellent Bare Metal Emulator for Raspberry Pi 3 [BMC64](https://accentual.com/bmc64/). With these modes, you can easily use your C-64 keyboard not even for emulating a Commodore-64 or VIC-20, but also a Commodore-128, a Plus/4 (or C-16), and even PET Computers with Graphics or Business keyboards, and having 100% keys functionality.

Keymmodore-64 is developed using a Raspberry Pi Pico and the powerful [QMK Firmware](https://qmk.fm/), so it is not a simple .ino sketch, or a MicroPython code. It runs the same type of code than many gaming keyboards have, and you can modifiy it if you want.

Just download the .zip file with the firmwares, and flash your Pi Pico with the .uf2 file, according your RGB LED polarity (common anode or cathode).

## A very important Note

In order to Keymmodore-64 to work correctly, you need two things:

- Set your Operative System Keyboard layout to "US" or "US International". Do not use any other layout. "UK",  "Spanish" or any other regional layout won't work properly.
- Download and use the .vkm files for your emulators. Set them as "User Positional" for each computer to be emulated. This make Emulation Modes work correctly with the Emulators. The default .vkm files do not work (being symbolic or positional).
- There is one VKM set of files for BMC64, and two sets for VICE, due to VICE having SDL2 and GTK3 builds.

### "The Matrix Reloaded"

The C-64 keyboard matrix is connected directly to the pins of the Pi Pico. However if you want to add Atari-like joysticks to your project, you need to add some wiring in between the keyboard connector and the Pico. As you can see in the matrix diagram below, P1 and P2 use the "I" file and the "8th" row of the RESTORE key. Remember, THIS IS OPTIONAL (just because there are some free crosspoints). If your are not interested in those old joysticks, or you plan to use a Raspberry (like a [Pimmodore-64](https://github.com/K-rnivoro/Pimmodore-64)), you do not need to add this extra complexity.

<img width="743" height="724" alt="image" src="https://github.com/user-attachments/assets/58894706-c022-432d-809c-ac3544666e7c" />

This is the schematics for connecting the C-64 keyboard and a RGB LED to the Pico (for common cathode RGB LED, just connect the common pin to any GND). There are also three pins reserved for an implementation with a Raspberry Pi 3, as you can see in my [Pimmodore-64](https://github.com/K-rnivoro/Pimmodore-64) project. Both RGB LED and the R-Pi 3 pins are not mandatory, however the RGB LED would be very cool and useful informing you which mode is the keyboard working, remember there are 6 different modes!

<img width="707" height="614" alt="image" src="https://github.com/user-attachments/assets/6ad6fff9-a5b4-494b-8b81-050176261a98" />

If you want to add the Atari-like joysticks, as mentioned, you will need to add some wiring in parallel in order to add the missing crosspoints to the matrix. And just in case, joysticks pinout is also shown.

<img width="269" height="427" alt="image" src="https://github.com/user-attachments/assets/515d8df5-a64a-4d11-b1a3-c8c2e1772d92" /> <img width="267" height="165" alt="image" src="https://github.com/user-attachments/assets/f6808798-8658-4c7d-be5e-651d5e3f20b6" />

For an easier connection between the Pico and the C-64 Keyboard, you can wire some dupont cable and comb connector like this one:


![Cable teclado](https://github.com/user-attachments/assets/1077820d-22c5-4e0d-95ea-607aa539847a)

If you decide to wire the joystick ports too, you have to work a little bit more on the soldering...


## How to switch to Compatible Modes

When Keymmodore-64 is powered from USB, the LED will go green, letting you know it's in "PC Compatible Mode" (explained below). From there you can switch to other Modes, compatibles with different VICE Emulators (VIC-20/C-64, C-128. Plus/4, PET Graphics/Business)

Pressing and holding Commodore Key (C=) along with CONTROL, F1, F3 or F5 keys, it will switch to different Modes (actually keyboards layouts), depending what computer you want to emulate in the emulator: 

- F1: Commodore-64, VIC-20 and Plus/4 Compatible Mode.
- F3: Commodore-128 Compatible Mode.
- F5: PET Graphics Keyboard Compatible Mode.
- F5 (again): PET Business Keyboard Compatible Mode (you need to be in PET Graphics Mode)
- CONTROL: Back to PC Compatible Mode.

To avoid any confussion, it is not possible to switch between two Emulator Modes (except PET Graphics to Business) . You have to switch back to PC Compatible Mode first by pressing C= and CONTROL. Also remember you need the configuration keyboard layout files for your emulator to work properly.  

If you wired the RGB LED it will show you which is the active mode as described below.

### RGB LED Color code

- PC Compatible Mode: GREEN
- Commodore-64, VIC-20 and Plus/4 Compatible Mode: RED
- Commodore-128 Compatible Mode: BLUE
- PET Graphics Keyboard Compatible Mode: YELLOW
- PET Business Keyboard Compatible Mode: PURPLE

In PC Compatible Mode and Commodore-128 Mode, while pressing the Right SHIFT (Modifier Key), the LED will light CYAN.

In any Mode, while pressing the Commodore Key (C=) the LED will light WHITE.

## PC Compatible Mode

In this Mode, the C-64 keyboard acts like a standard PC Keyboard, keeping the original layout as far as possible, but also remapping non-existent ones to modern functions. Considering the C-64 had no Numeric KeyPad, nor complete set of Function Keys (F1 a F12),  the paradigm is similar to “60%” Keyboards, using Special Function Keys (Fn y Fn2) allowing the same key having more than one function. In the following pic, the PC Mode layout is shown. This is the mode when you plug your keyboard. In light brown you can see the keys having different assignments than the original C-64 Keyboard, as described below.

<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/acb42d1a-71bf-4544-9131-2dcf0950dc6b" />

### EXCLUSIVE C-64 KEYS:
- RUN/STOP works as Left ALT.
- RESTORE works as BACKSPACE
- ← (Left Arrow) works as ESCAPE, or ~  (diacritic) if SHIFT is held.
- £ works as \ (inverted slash), o | (pipe) if SHIFT is held.
- 0 key works as ^ (circumflex accent) when SHIFT is held.
- ↑ (Up Arrow) moves the cursor up.
- – (Minus) works as _ (underscore) when SHIFT is held.
- Cursor keys (↑/↓) y (←/→) will work down (↓) and right (→) unless right SHIFT is being pressed as described below.
- @ (At), * (Asterisk), = (Equal) and + (Plus) will work as such, regardless SHIFT being held or not.


### LEFT CONTROL and TAB in one key.

This is maybe one of the coolest feature of QMK Firmware. Due to the fact that the CONTROL key is located in the same place than TAB in a regular PC Keyboard, Keymmodore-64 implements a dual role fot this key. If you tap it (meaning press and release without pressing another key) it will work as a TAB; however if you press and hold, and press another key, it will work as a CONTROL allowing the combination with other keys, like CTRL+C, CTRL+V, etc. Cool uh?


### LEFT SHIFT AND SHIFT LOCK.

The Left SHIFT works like any standard PC Keyboard, allowing access to capital letters and additional characters as usual. The SHIFT LOCK key is actually wired to the Left SHIFT, but with a mechanical lock so it is not the same than a real CAPS LOCK, affecting also the 0 a 9 keys.


### COMMODORE (C=) key as FUNCTION “Fn” key.

The key with  the C= symbol on it, generally called «Commodore Key», works also a Modification key allowing to access to a different layers and function like a “60%” Style Keyboards.

In the following diagram you can see in white which keys will change its function when Fn  (C=) is pressed. Some functions are already in the legends of the keys, and others are added to better productivity.

<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/102fc4d9-a8c2-44eb-8ace-db79c0e66528" />

So, pressing Commodore key:

- 1 to 0 keys, as well as + y – will work as F1 to F12
- HOME key works as END
- INST/DEL key works as INSERT as the top legend.
- ↑ and RESTORE keys works as PAGE UP y PAGE DOWN respectively.
- ↓ and → cursor keys work up (↑) and left (←) respectively, as the top legend described.
- Q and E, as well as U and O keys, work as PAGE UP and PAGE DOWN respectively.
- WASD and IJKL work as directional cursor  ↑ ←↓ → respectively.
- ← key work as ` (grave tilde), and ~ (diacritic).
- : (colon) and ; (semicolon) work as { and } (brackets) respectively.
- P key works as PRINT SCREEN.
- @ (at) key works enabling and disabling SCROLL LOCK.
- * (asterisk) key works enabling and disabling NUM LOCK  (very important for joysticks). 
- < (less than) y > (greater than) decrease and increase audio volume respectively (*).
- / (slash) mutes the audio output (*).
- C fires the Calculator (if supported by the Operative System).

### RIGHT SHIFT AS FUNCTION “Fn2” Key.

The RIGHT SHIFT besides being a regular Shift for most of the keys, works also a Function as explained:

<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/f63dd00c-08ce-4ba8-8270-5038941cd58d" />

Pressing RIGHT SHIFT:
- ↓ (Cursor Down) and → (Cursor Right) keys invert their direction, working as Up (↑) y Left (←) respectively, as the top legend describe (in the same way C-64 does).
- The F1, F3, F5 and F7 function keys work as F2, F4, F6 and F8, as the top legend describe (in the same way C-64 does).

## Commodore-64, VIC-20 and Plus/4 Compatible Mode.

As explained before, pressing C= Key and F1, the interfase switches to this compatible Mode. Depending the computer being emulated in the emulator (and the right .vkm files), you will have the following layouts:

### COMMODORE-64 AND VIC-20

<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/03dd081a-8797-4447-872e-f3c166db8175" />

In this Mode, the keyboard work exactly as it was original conceived for C-64 or VIC-20, including all the symbols and legends of the keys. Remember to press C= and CONTROL to go back to PC Compatible Mode when you exit your emulator.

### COMMODORE PLUS/4 or COMMODORE-16 (or any other C-264 Model)

Emulating a Plus/4 or similar machine, the C-64 keyboard will behave like a C-16 keyboard. With the intention to make it intuitive, instead of keeping the original position of keys of a C-16 keyboard, I’ve changed the location of some keys keeping the original C-64 layout as much as possible.

<img width="1024" height="282" alt="image" src="https://github.com/user-attachments/assets/db3d46e8-c04e-4814-a5d5-446a60784d44" />

As you can see, location of – (minus), * (asterisk), + (add), = (equal), £ (pound) and CLEAR/HOME are the same than C-64.

The changes are:

- The original C-64 cursor keys work as ↓ (Down) and → (Right). SHIFT won’t invert the direccion of these two as it does in the C-64.
- ↑ (Arrow Up) and RESTORE work as ↑ (Up) and ← (Left) respectively.
- F1, F3, F5 and F7 work as F1, F2, F3 and HELP respectively, including switching to F4, F5, F6 and F7  if SHIFT is pressed.

Remember to press C= and CONTROL keys to switch back to PC Compatible Mode.

## Commodore-128 Compatible Mode.

Due to having more keys than a C-64 keyboard, the RIGHT SHIFT is implemented as a FUNCTION or Modifier Key, allowing to to access to the propietary keys of the C-128 which are mapped on the C-64 keyboard in this way:

<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/ca4b3700-139b-4932-b9c7-5f5940c27530" />

So, pressing RIGHT SHIFT and the 1/! key, will result in a "1" instead of a "!", because it corresponds to the Key 1 of the Numerical Pad, not the regular 1 Key.

Remember to press C= and CONTROL keys to switch back to PC Compatible Mode.

## Commodore PET Graphics Keyboard Compatible Mode.

Commodore PET has two different keyboards layout, so both need to be emulated separately.

The first mode allows to emulate the so called «Graphics» keyboards, the one with PETSCII graphics used by the early Commodore PET Series Computer. This Graphics keyboard has an odd layout where every symbol has their own key, and also there is just one PETSCII graphics per key instead of two as found in C-64 Keyboard.
Look how weird it is:

<img width="1000" height="294" alt="image" src="https://github.com/user-attachments/assets/508a0dce-3a4c-4385-b2e6-906934558163" />

In this Mode, the layout of your C-64 keyboard will be the following:

<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/b986ce41-3792-4ebf-a542-d8037283bc3e" />


- CTRL key works as OFF/RVS.
- £ (pound) key works a \ (backslash).
- RESTORE key works as second INST/DEL.
- C= does not exist in PET Graphics Keyboard, however we will use it to access PETSCII graphics set as explained below.
- Function Keys (F1 to F8) do not exist in PET Graphics Keyboard, therefore they have no function. 

### ACCESS TO SYMBOL KEYS AND PETSCII GRAPHICS

As mentioned, every symbol have it's own key. In order to access those keys, the C= Key is used a FUNCTION or Modifier Key. So, for symbols in the upper part of the key (or "shifted") just press C= and the key with the symbol you want. .

Regarding PETSCII graphics, the character set is identical to the C-64, despite having just one PETSCII for each key. Keymmodore-64 implements a cool feature, able to «merge» again those two PETSCII in a single key, with the same layout than the C-64. Therefore, you can access both in the usual way: The left side ones with the C= key, and the right side ones with any SHIFT key. This also works for the π symbol of the Up Arrow Key (↑).

Joining both features, in the following diagram you can see in green the functions with C= key, and in yellow the function with any of the two SHIFT, which matches most of the layout of the C-64 keyboard.


<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/ea104305-b933-44f2-ba22-5faf6afe4fc4" />


Pressing C= and CONTROL keys switch back to PC Compatible Mode. However, pressing C= and F5 keys again, switch to PET Business Keyboard Compatible Mode as explained below.


## Commodore PET Business Keyboard Compatible Mode.

This second mode allows to emulate the so called «Business» keyboard (the one with upper and lower case letters) used by the later Commodore PET Series Computer. This keyboard has some particular symbolic only keys like Brackets ([ ]), minus and equal (- =), asterisk and colon (: *). It's weird like the Graphics keyboard, but not that weird.

<img width="1024" height="287" alt="image" src="https://github.com/user-attachments/assets/148a0fb9-7d53-4e0f-9466-30efb323b4fb" />

Mapping the Business keyboard to the C-64 keyboard is pretty straightforward, although some keys change its position. 

You can see the differences in the following diagram:

<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/f2023e57-2a4e-4a6a-b023-f4467634eecd" />


- CTRL key works as TAB.
- £ (Pound) key works as \ (backslash).
- RESTORE key works as second INST/DEL.
- F1 key works as ESC.
- F3 key works as OFF/RVS.
- F5 key works as REPEAT.
- F7 key have no function.

### ACCESS TO NUMERIC PAD AND BRACKET KEYS

Keymmodore-64 implements a special layer with the C= key for those special keys. You can see in green the keys that change its function if you keep C= key pressed.

<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/9ff61c5f-01b7-4932-9020-95c53a9c24f8" />

As usual, C= and CONTROL keys switch back to PC Compatible Mode.

## Putting your Keymmodore-64 interface inside your C-64 case.

I've created some 3D frames if you want to install the Pico board inside a C-64 case. You can download the .zip containing the .stl files. 

There are two options: With Joysticks ports or with no joysticks.
It can be screwed to the right side of your bottom part of the case. It uses the same screw holes than the original PCB.
I've made them in Sketchup (.skp) in case you want to download and improve it.

For a "full" set of frames using a Raspberry Pi, check my other project  [Pimmodore-64](https://github.com/K-rnivoro/Pimmodore-64)).

A pic of the frame (no joysticks option) installed in the case:

![Keymmodore1](https://github.com/user-attachments/assets/4a9a1fd1-4f34-4191-afda-6915668a009f)

With keyboard connected (LED connection not shown):

![Detalle Cable](https://github.com/user-attachments/assets/4e2fdd49-3f8e-441e-bd00-87b3bba21217)


















