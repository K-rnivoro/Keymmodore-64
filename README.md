# Keymmodore-64
# An interfase for converting a Commodore-64 Keyboard to USB, 100% compatible with PC/Linux/Android.

The Keymmodore-64 project is an interfase to convert keyboards and joysticks of Commodore computers in a USB device able to be connected to any Operative System with USB HID (Human Interfase Device) compatibility, like: PC (Windows/Linux), Raspberry Pi, Mac,  and even Android. Therefore, the keyboard works like any other keyboard, optionally you can connect old Atari-like joysticks and their inputs would be translated to key strokes too.

In order to make a C-64 keyboard productive, Keymmodore-64 includes a lot of useful combinations of keystrokes, using keys as Function keys (like the Commodore key). This way, your C-64 Keyboard includes almost all keys you need for your everyday work.

Besides the standard "PC Mode" describes above, Keymmodore-64 also includes five modes optimized for all 8 bit Commodore Computers emulators, like VICE or BMC64. Using these modes, you can easily use your C-64 keyboard not even emulating a Commodore-64 or VIC-20, but also a Commodore-128, a Plus/4 (or C-16), and even PET Computers with Graphics or Business keyboards.

Keymmodore-64 is developed using a Raspberry Pi Pico and the powerful QMK Firmware, so it is not a simple .ino sketch, or a MicroPython code. It runs the same type of code than many gaming keyboards have, and you can modifiy it if you want.

The C-64 keyboard matrix is connected directly to the pins of the Pi Pico. However if you want to add Atari-like joysticks to your project, you need to add some wiring in between the keyboard connector and the Pico. As you can see in the matrix diagram below, P1 and P2 use the "I" file and the "8" row of the RESTORE key. Remember, THIS IS OPTIONAL (just because there are some free crosspoints). If your are not interested in those old joysticks, or you plan to use a Raspberry (like a Pimmodore-64), you do not need to add this extra complexity.

<img width="743" height="724" alt="image" src="https://github.com/user-attachments/assets/58894706-c022-432d-809c-ac3544666e7c" />

Just in case you want to connect the joysticks, remember the correct wiring:

<img width="267" height="165" alt="image" src="https://github.com/user-attachments/assets/f6808798-8658-4c7d-be5e-651d5e3f20b6" />

This is the schematics for connecting the C-64 keyboard and a RGB LED to the Pico. There are also three pins reserved for an implementation with a Raspberry Pi 3, as you can see in my Pimmodore-64 project. Both RGB LED and the R-Pi 3 pins are not mandatory, however the RGB LED would be very cool and useful informing you which mode is the keyboard working, remember there are 6 different modes!

<img width="945" height="601" alt="image" src="https://github.com/user-attachments/assets/a0c23ce0-b825-4167-b8d1-8370b28ff772" />




