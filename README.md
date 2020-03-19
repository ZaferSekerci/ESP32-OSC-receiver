# ESP32-OSC-receiver
Open Sound Control (OSC) receiver for esp32 over WiFi

Get OSC values and show them to Nokia 5110 lcd screen

Things to do to run the project with default settings
* First of all, this project written with Visual Studio Code and PlatformIO extension.
if you use platformIO too, 5110 and OSC libraries download automatically by platformio.
* Wire up Nokia 5110 LCD screen to esp32 (pin numbers are at the beginning of the code)
* Change WiFi network settings (ssid, password and ip address)
* Send OSC values to slider0,slider1,slider2,slider3,slider4,slider5 and you must see the values at the LCD
