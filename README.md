# Keymmodore-64
# An interfase for converting a Commodore-64 Keyboard to USB, 100% compatible with PC/Linux/Android.

The Keymmodore-64 project is an interfase to convert keyboards and joysticks of Commodore computers in a USB device able to be connected to any Operative System with USB HID (Human Interfase Device) compatibility, like: PC (Windows/Linux), Raspberry Pi, Mac,  and even Android. Therefore, the keyboard works like any other keyboard, optionally you can connect old Atari-like joysticks and their inputs would be translated to key strokes too.

In order to make a C-64 keyboard productive, Keymmodore-64 includes a lot of useful combinations of keystrokes, using keys as Function keys (like the Commodore key). This way, your C-64 Keyboard includes almost all keys you need for your everyday work.

Besides the standard "PC Mode" describes above, Keymmodore-64 also includes five modes optimized for all 8 bit Commodore Computers emulators, like VICE or BMC64. Using these modes, you can easily use your C-64 keyboard not even emulating a Commodore-64 or VIC-20, but also a Commodore-128, a Plus/4 (or C-16), and even PET Computers with Graphics or Business keyboards.

Keymmodore-64 is developed using a Raspberry Pi Pico and the powerful QMK Firmware, so it is not a simple .ino sketch, or a MicroPython code. It runs the same type of code than many gaming keyboards have, and you can modifiy it if you want.

The C-64 keyboard matrix is connected directly to the pins of the Pi Pico. However if you want to add Atari-like joysticks to your project, you need to add some wiring in between the keyboard connector and the Pico. As you can see in the matrix diagram below, P1 and P2 use the "I" file and the "8" row of the RESTORE key. Remember, THIS IS OPTIONAL (just because there are some free crosspoints). If your are not interested in those old joysticks, or you plan to use a Raspberry (like a Pimmodore-64), you do not need to add this extra complexity.

<img width="743" height="724" alt="image" src="https://github.com/user-attachments/assets/58894706-c022-432d-809c-ac3544666e7c" />

This is the schematics for connecting the C-64 keyboard and a RGB LED to the Pico. There are also three pins reserved for an implementation with a Raspberry Pi 3, as you can see in my Pimmodore-64 project. Both RGB LED and the R-Pi 3 pins are not mandatory, however the RGB LED would be very cool and useful informing you which mode is the keyboard working, remember there are 6 different modes!

<img width="707" height="614" alt="image" src="https://github.com/user-attachments/assets/6ad6fff9-a5b4-494b-8b81-050176261a98" />

If you want to add the Atari-like joysticks, as mentioned, you will need to add some wiring in parallel in order to add the missing crosspoints to the matrix. And just in case, joysticks pinout is also shown.

<img width="269" height="427" alt="image" src="https://github.com/user-attachments/assets/515d8df5-a64a-4d11-b1a3-c8c2e1772d92" /> <img width="267" height="165" alt="image" src="https://github.com/user-attachments/assets/f6808798-8658-4c7d-be5e-651d5e3f20b6" />

# PC Compatible Mode

In this Mode, the C-64 keyboard acts like a standard PC Keyboard, keeping the original layout as far as possible, but also remapping non-existent ones to modern functions. Considering the C-64 had no Numeric KeyPad, nor complete set of Function Keys (F1 a F12),  the paradigm is similar to “60%” Keyboards, using Special Function Keys (Fn y Fn2) allowing the same key having more than one function. In the following pic, the PC Mode layout is shown. This is the mode when you plug your keyboard. In light brown you can see the keys having different assignments than the original C-64 Keyboard, as described below.

<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/acb42d1a-71bf-4544-9131-2dcf0950dc6b" />

EXCLUSIVE C-64 KEYS:
- RUN/STOP turns to Left ALT.
- RESTORE turns to BACKSPACE
- ← (Left Arrow) turns to ESCAPE, or ~  (diacritic) if SHIFT is held.
- £ turns to \ (inverted slash), o | (pipe) if SHIFT is held.
- 0 key is also ^ (circumflex accent) if SHIFT is held.
- ↑ (Up Arrow) moves the cursor up.
- – (Minus) is also _ (underscore) if SHIFT is held.
- Cursor keys (↑/↓) y (←/→) will work down (↓) and right (→) unless right SHIFT is being pressed as described below.
- @ (At), * (Asterisk), = (Equal) and + (Plus) will work as such, regardless SHIFT being held or not.


LEFT CONTROL and TAB in one key.

This is maybe one of the coolest feature of QMK Firmware. Due to the fact that the CONTROL key is located ijn the same place than TAB in a regular PC Keyboard, Keymmodore-64 implements a dual role fot this key. If you tap it (meaning press and release without pressing another key) it will work as a TAB; however if you press and hold, and press another key, it will work as a CONTROL allowing the combination with other keys, like CTRL+C, CTRL+V, etc. Cool uh?


LEFT SHIFT AND SHIFT LOCK.

The Left SHIFT works like any standard PC Keyboard, allowing access to capital letters and additional characters as usual. The SHIFT LOCK key is actually wired to the Left SHIFT, but with a mechanical lock so it is not the same than a real CAPS LOCK, affecting also the 0 a 9 keys.

RIGHT SHIFT AS FUNCTION “Fn2” Key.

The RIGHT SHIFT besides being a regular Shift for most of the keys, works also a Function as explained:

<img width="1024" height="284" alt="image" src="https://github.com/user-attachments/assets/f63dd00c-08ce-4ba8-8270-5038941cd58d" />

Pressing RIGHT SHIFT:
- ↓ (Cursor Down) and → (Cursor Right) keys invert their direction, working as Up (↑) y Left (←) respectively, as the top legend describe (in the same way C-64 does).
- The F1, F3, F5 and F7 function keys work as F2, F4, F6 and F8, as the top legend describe (in the same way C-64 does).


COMMODORE (C=) key as FUNCTION “Fn” key.

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








