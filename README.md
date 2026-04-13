<img width="1200" height="150" alt="KEYmmodore_64-3" src="https://github.com/user-attachments/assets/27513dbf-624a-4bcf-a6cf-d66e24ab118c" />

## An interface for converting a Commodore-64 Keyboard to USB, compatible with any Operative System, and VIC-20, C-64, C-128, Plus/4 and PET emulators.

The Keymmodore-64 project is a hardware interface to convert keyboards and joysticks of Commodore C-64 computer, in a USB (HID) device, able to be connected to any "Host" computer or device, like: PC (Windows/Linux), Raspberry Pi, Mac, or even Android. Therefore, the keyboard works like any other keyboard, optionally you can connect old Atari-like joysticks and their inputs would be translated to keystrokes too.

It's also part of my other project [Pimmodore-64](https://github.com/K-rnivoro/Pimmodore-64) in case you're thinking matching it with a Raspberry Pi 3.

In order to make a C-64 keyboard productive for a PC, Keymmodore-64 includes a lot of key combinations, like using the Commodore key as Function Key. This way, your C-64 Keyboard includes almost all keys you need for your everyday work.

Besides the standard "PC Mode", Keymmodore-64 also includes five modes optimized for all 8 bit Commodore Computers emulators, like [VICE](https://vice-emu.sourceforge.io/) or the excellent Bare Metal Emulator for Raspberry Pi 3 [BMC64](https://accentual.com/bmc64/). With these modes, you can easily use your C-64 keyboard not even for emulating a Commodore-64 or VIC-20, but also a Commodore-128, a Plus/4 (or C-16), and even PET Computers with Graphics or Business keyboards, and having 100% keys functionality.

Keymmodore-64 is developed using a Raspberry Pi Pico and the powerful [QMK Firmware](https://qmk.fm/), so it is not a simple .ino sketch, or a MicroPython code. It runs the same type of code than many gaming keyboards have, and you can modifiy it if you want.

Just download the .zip file with the firmwares, and flash your Pi Pico with the .uf2 file, according your RGB LED polarity (common anode or cathode).

## A very important Note

In order to Keymmodore-64 to work correctly, you need a few things:

- Set your Operative System Keyboard layout to "US" or "US International". Do not use any other layout. "UK",  "Spanish" or any other regional layout won't work properly.
- Download and use the .vkm files for your emulators. Set them as "User Positional" for each computer to be emulated. This make Emulation Modes work correctly with the Emulators. The default .vkm files do not work (being symbolic or positional).
- There is one VKM set of files for BMC64, and two sets for VICE, due to VICE having SDL2 and GTK3 builds, although GTK3 is preferred as explained below.

### "The Matrix Reloaded"

The C-64 keyboard matrix is connected directly to the pins of the Pi Pico. However if you want to add Atari-like joysticks to your project, you need to add some wiring in between the keyboard connector and the Pico. As you can see in the matrix diagram below, P1 and P2 use the "I" line and the "8th" row of the RESTORE key. Remember, THIS IS OPTIONAL (just because there are some free crosspoints). If your are not interested in those old joysticks, or you plan to use a Raspberry (like a [Pimmodore-64](https://github.com/K-rnivoro/Pimmodore-64)), you don't need to add this extra complexity.

<img width="743" height="724" alt="image" src="https://github.com/user-attachments/assets/58894706-c022-432d-809c-ac3544666e7c" />

This is the schematics for connecting the C-64 keyboard and a RGB LED to the Pico (for common cathode RGB LED, just connect the common pin to any GND). There are also three pins reserved for an implementation with a Raspberry Pi 3, as you can see in my [Pimmodore-64](https://github.com/K-rnivoro/Pimmodore-64) project. RGB LED is not mandatory, however it's very useful giving you information about which mode is the keyboard working, remember there are 6 different modes!

<img width="707" height="614" alt="image" src="https://github.com/user-attachments/assets/6ad6fff9-a5b4-494b-8b81-050176261a98" />

If you want to add the Atari-like joysticks, as mentioned, you will need to add some wiring in parallel in order to add the missing crosspoints to the matrix. And just in case, joysticks pinout is also shown.

<img width="269" height="427" alt="image" src="https://github.com/user-attachments/assets/515d8df5-a64a-4d11-b1a3-c8c2e1772d92" /> <img width="267" height="165" alt="image" src="https://github.com/user-attachments/assets/f6808798-8658-4c7d-be5e-651d5e3f20b6" />

For an easier connection between the Pico and the C-64 Keyboard, you can wire some dupont cable and comb connector like this one:


![Cable teclado](https://github.com/user-attachments/assets/1077820d-22c5-4e0d-95ea-607aa539847a)

If you decide to wire the joystick ports too, you have to work a little bit more on the soldering...

![cables pimmodore](https://github.com/user-attachments/assets/37b49878-31eb-485e-99a9-d5fc397ed77d)


## How to properly solder the pins to the Pico.

I suggest you to solder the pins to each side of the Pico, in the same side than the components, so you connect the dupont cables on the other side, as shown here:

<img width="857" height="718" alt="image" src="https://github.com/user-attachments/assets/580b2233-7151-4d68-8261-b34dd08d2cec" />

This is important if you plan to print the holder (explained below), or build a [Pimmodore-64](https://github.com/K-rnivoro/Pimmodore-64)


## How to switch to Compatible Modes

When Keymmodore-64 is powered from USB, the LED will go green, letting you know it's in "PC Compatible Mode" (explained below). From there you can switch to other Modes, compatibles with different VICE Emulators (VIC-20/C-64, C-128. Plus/4, PET Graphics, PET Business)

Commodore Key (C=) behaves like a Special Function (FN) key. So pressing it along with F1, F3, F5 or CONTROL key, the interface will switch to different Modes (actually keyboards layouts), depending what computer you want to emulate in the emulator: 

<img width="2067" height="499" alt="Keymmodore Mode switching" src="https://github.com/user-attachments/assets/4ab23ba0-f3e2-4693-b70b-42422fd2fb4f" />


- F1: Commodore-64, VIC-20 and Plus/4 Compatible Mode.
- F3: Commodore-128 Compatible Mode.
- F5: PET Graphics Keyboard Compatible Mode.
- F5 (again, from PET Graphics): PET Business Keyboard Compatible Mode.
- CONTROL: Back to PC Compatible Mode.
- F7: This key is reserved for the BMC64 emulator Menu, when used as Pimmodore-64.

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

In this Mode, the C-64 keyboard acts like a standard PC Keyboard, keeping the original layout as far as possible, but also remapping non-existent ones to modern functions. Considering the C-64 had no Numeric KeyPad, nor complete set of Function Keys (F1 a F12),  the paradigm is similar to “60%” Keyboards, using Special Function Keys (like Fn) allowing the same key having more than one function. In the following pic, the PC Mode layout is shown. This is the mode when you plug your keyboard. In light brown you can see the keys having different assignments than the original C-64 Keyboard, as described below.

<img width="1834" height="514" alt="Keymmodore PC Mode" src="https://github.com/user-attachments/assets/8aa26202-1a7d-447d-bf52-139f81c44237" />


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

In the diagram you can see in yellow which keys will change its function when Fn (C=) is pressed. Some functions are already in the legends of the keys, and others are added to better productivity.

- RUN/STOP works as Left GUI key (also called Windows key).
- 1 to 0 keys, as well as + y – will work as F1 to F12
- HOME key works as END
- INST/DEL key works as INSERT as the top legend.
- ↑ and RESTORE keys works as PAGE UP y PAGE DOWN respectively.
- ↓ and → cursor keys work up (↑) and left (←) respectively, as the top legend described.
- WASD and IJKL work as directional cursor  ↑←↓→ respectively.
- ← (left arrow) key work as ` (grave tilde), and ~ (diacritic).
- : (colon) and ; (semicolon) work as { and } (brackets) respectively.
- P key works as PRINT SCREEN.
- @ (at) key works enabling and disabling SCROLL LOCK.
- * (asterisk) key works as PAUSE.
- N key enables and disables NUM LOCK (This seems trivial for a non-numpad keyboard, but it is very important for joysticks to work to have NUM LOCK enabled). 
- < (less than) y > (greater than) decrease and increase audio volume respectively (*).
- / (slash) mutes the audio output (*).
- C fires the Calculator (*).

(*) If supported by the Operative System.

### RIGHT SHIFT AS SECOND FUNCTION Key.

The RIGHT SHIFT besides being a regular Shift for most of the keys, works also a second function key, as shown in green in the diagram above:

- ↓ (Cursor Down) and → (Cursor Right) keys invert their direction, working as Up (↑) y Left (←) respectively, as the top legend describe (in the same way C-64 does).
- The F1, F3, F5 and F7 function keys work as F2, F4, F6 and F8, as the top legend describe (in the same way C-64 does).

## Commodore-64, VIC-20 Compatible Mode.

As explained before, pressing C= Key and F1, the interfase switches to this compatible Mode. Depending the computer being emulated in the emulator (and the right .vkm files), you will have the following layouts:

### COMMODORE-64 AND VIC-20

<img width="1836" height="513" alt="Keymmodore VIC20-C64 Mode" src="https://github.com/user-attachments/assets/30e80457-07e3-45c9-ab0d-e71ef492bc46" />


In this Mode, the keyboard work exactly as it was original conceived for C-64 or VIC-20, including all the symbols and legends of the keys. The only added functionality is pressing C= and CONTROL goes back to PC Compatible Mode, so you can switch between your Emulator and Operative System.

### COMMODORE PLUS/4 (or any other C-264 Model) Compatible Mode.

![Plus4 Keyboard](https://github.com/user-attachments/assets/4e62082b-f0dd-448a-a269-8527adb85d9f)


While emulating a Plus/4 or similar machine, the C-64 keyboard will behave like a C-16 keyboard. With the intention to make it intuitive, instead of keeping the original position of keys of a C-16 keyboard, I’ve changed the position of some keys to match the original C-64 layout.

<img width="1837" height="507" alt="Keymmodore C16 Mode" src="https://github.com/user-attachments/assets/4e1cf5ce-1612-4753-b2cf-5de7bfaca626" />

As you can see, position of – (minus), * (asterisk), + (add), = (equal), £ (pound) and CLEAR/HOME are the same than C-64.

The changes are:

- The original C-64 cursor keys work as ↓ (Down) and → (Right). SHIFT won’t invert the direccion of these two, as it does in the C-64.
- ↑ (Arrow Up) and RESTORE work as ↑ (Up) and ← (Left) respectively.
- F1, F3, F5 and F7 work as F1, F2, F3 and HELP respectively, including switching to F4, F5, F6 and F7  if SHIFT is pressed.

Press C= and CONTROL keys to switch back to PC Compatible Mode.

## Commodore-128 Compatible Mode.

Implementing C-128 Keyboard is a challenge due to having more keys than a C-64 keyboard. 

![C128 Keyboard](https://github.com/user-attachments/assets/a6c9ae8e-5ff7-4801-b1d1-0fb5b991510b)


This is the diagram of a C-128 Keyboard in a C-64 one:

<img width="1836" height="513" alt="Keymmodore C128 Mode" src="https://github.com/user-attachments/assets/178ce660-af07-4698-a3f5-b80b5622002f" />

### Exclusive C-128 Keys.

Because implementing C= as Modifier Key is not possible due to being used by the computer itself, RIGHT SHIFT is mapped as a Function or Modifier Key, allowing access to the propietary keys of the C-128 which are mapped on the C-64 keyboard in this way (marked in green):

- Left Arrow key, will result in ESC key.
- Pressing first first row keys, from 1 (one) to - (minus) keys, will result in the corresponding Numerical Pad key. For example, pressing 1/! will result in a "1" instead of a "!", because it corresponds to the Key 1 of the Numerical Pad, not the regular 1 Key.
- CONTROL key is TAB.
- RUN/STOP is ALT.
- Up Arrow key is CAPS LOCK.
- RETURN is Numpad´s RETURN.
- \>/. is Numpad´s decimal.
- F1 in HELP.
- F3 is LINE FEED.
- F5 is 40/80 DISPLAY.
- F7 is NO SCROLL.

### CURSOR Keys in C-128 Mode.

C-128 has double set of cursor keys: The regular two C-64 keys, and the exclusive four C-128 independent keys. So, the two C-64 keys work this way:

- With no modifier key pressed, they work as originally labeled: Down and Right respectively.
- With Left SHIFT key, they work also as original labeled too: Up and Left.
- With RIGHT SHIFT key, they work as Up and Left C-128 exclusive keys.
- With Commodore Key (C=) they work as Down and Right C-128 exclusive keys (pretty stupid but necessary for completeness)

As usual, C= and CONTROL keys switch back to PC Compatible Mode.

## Commodore PET Graphics Keyboard Compatible Mode.

Commodore PET has two different keyboards layout, so both need to be emulated separately.

The first mode allows to emulate the so called «Graphics» keyboards, the one with PETSCII graphics used by the early Commodore PET Series Computer. This Graphics keyboard has an odd layout where every symbol has their own key, and also there is just one PETSCII graphics per key instead of two as found in C-64 Keyboard.
Look how weird it is:

![PET Graphics Keyboard](https://github.com/user-attachments/assets/86339b22-2229-4c00-950c-4876ef8f2f1c)


In this Mode, the layout of your C-64 keyboard will be the following:


<img width="1836" height="515" alt="Keymmodore PET Graphics Mode" src="https://github.com/user-attachments/assets/a81fe50f-791e-491f-9495-8e7d1d03f7d2" />

### REGULAR PET GRAPHICS KEYS

- CTRL key works as OFF/RVS.
- £ (pound) key works a \ (backslash).
- RESTORE key works as second INST/DEL.
- C= does not exist in PET Graphics Keyboard, however we will use it to access PETSCII graphics set as explained below.
- Function Keys (F1 to F8) do not exist in PET Graphics Keyboard, however F5 is used as explained below. 

### SYMBOLS AND PETSCII GRAPHICS

As mentioned, every symbol have it's own key. In order to access those keys, the C= Key is used a FUNCTION or Modifier Key. So, for symbols in the upper part of the key (or "shifted") just press C= and the key with the symbol you want.

Regarding PETSCII graphics, the character set is identical to the C-64, despite having just one PETSCII for each key. Keymmodore-64 implements a cool feature, able to «merge» again those two PETSCII graphics in a single key, with the same layout than the C-64. Therefore, you can access both in the usual way: The left side ones with the C= key, and the right side ones with any SHIFT key. This also works for the π symbol of the Up Arrow Key (↑).

Joining both features, in the diagram above you can see in green the functions with C= key, and in yellow the function with any of the two SHIFT, which matches most of the layout of the C-64 keyboard.

### Switching to PET Business Mode or PC Mode

Pressing C= and CONTROL keys switch to PC Compatible Mode. Also, pressing C= and F5 keys again, switch to PET Business Keyboard Compatible Mode.

### A note about SDL2 Winvice: 

Due to some limitations of how SDL2 works (or mine as a programmer) some PETSCII graphics won't match the corresponding key in combination with SHIFT, particulary symbol keys: @/*/+/-/£. Therefore, GTK3 is preferred.


## Commodore PET Business Keyboard Compatible Mode.

This second mode allows to emulate the so called «Business» keyboard (the one with upper and lower case letters) used by the later Commodore PET Series Computer.

You can´t switch from PC Mode to PET Business Mode directly, first you have to switch to Graphics Mode, then to Business Mode (Only four Functions key, sorry...)

This keyboard has some particular symbolic only keys like Brackets ([ ]), minus and equal (- =), asterisk and colon (: *). It's weird like the Graphics keyboard, but not that weird.

<img width="1024" height="287" alt="image" src="https://github.com/user-attachments/assets/148a0fb9-7d53-4e0f-9466-30efb323b4fb" />

Mapping the Business keyboard to the C-64 keyboard is pretty straightforward, although some keys change its position as seen in the following diagram: 


<img width="1837" height="513" alt="Keymmodore PET Business Mode" src="https://github.com/user-attachments/assets/d25669a1-2dbf-4fc4-9e9b-b174c81ce19e" />


### EXCLUSIVE KEYS

- CTRL key works as TAB.
- £ (Pound) key works as \ (backslash).
- RESTORE key works as second INST/DEL.
- F1 key works as ESC.
- F3 key works as OFF/RVS.
- F5 key works as REPEAT.
- F7 key have no function.

### NUMERIC PAD AND BRACKET KEYS

Keymmodore-64 implements a layer with the C= key for those special keys. You can see in green the keys that change its function if you keep C= key pressed.

- 1 to 0 keys, correspond to Numpad keys. So for example pressing C= and 1 key, is actually Numpad´s 1 key, not the regular 1 key.
- \>/. key is mapped to Numpad´s Decimal key
- \[/: and ]/; keys correspond to those particular symbol-only Open and Close Bracket keys respectively.
   
As usual, C= and CONTROL keys switch back to PC Compatible Mode.


## How to test your Keyboard

Use a Keyboard testes. There is a lot of them out there, but I found [Switch Hitter](https://www.majorgeeks.com/files/details/switch_hitter.html) being the best (for Windows).


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















