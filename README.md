# Keymmodore-64 for Teensy++ 2.0
An interface for Commodore-64 Keyboard to USB for Teensy++ 2.0, 100% compatible with PC/Linux/Android.
Also 4 layouts or mappting for emulation compatibility with C-64, Plus/4,C-16, C-128 and PET (Graphics and Business)

Some changes were done to the Teensy++2 pinout described in the original project:https://www.keymmodore.com/teensy-2-0-for-c-64/

Teensy ++2Pin | Previous      | Now
--------------|---------------|------------
PA0           | Not used      | LED Pin Red
PA1           | Not used      | LED Pin Cathode/Anode
PA2           | Not used      | LED Pin Green
PA3           | Nod Used      | LED Pin Blue
PB4           | LED Pin Blue  | RPI GPIO 26
PB5           | LED Pin Red   | RPI GPIO 20
PB6           | LED Pin Green | RPI GPIO 21
5V            | LED Cath/Anod | Not Used

![Teensy Wiring](teensy%2B%2B2.0-wiring.png)