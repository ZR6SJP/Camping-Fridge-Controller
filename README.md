# Introduction

I have been tasked to create a controller for a camping fridge, this will work by checking the temperatur of it using a thermometer(DS18B20).
It will also display the temperature, voltage of the battery the camping fridge is connected to, and various other things in the futre.
It uses the ESP32 as a controller for it, the idea is an app will be made in the future so it can easily be viewed using a phone for now a Serial Bluetooth Terminal app was used..


# Journal Log
Date: 17 August 2023
This is to test and check if it is possible and works. Currently it measures temperature and the voltage measuring is in the works, it sends the information using bluetooth, every 5 seconds, to a "terminal" on your phone.

Date: 4 September 2023
During the week before the 28th August 2023 I got the voltage measuring to work, I however encountered a problem the ADC pins on a ESP32 inaccurate accurate, by manipulating the voltage data from the ESP32 using the following formula (Voltage_Value/4096)*26.5 the voltage value the ESP32 reads becomes closer to the actual reading. 

For the use case in camping the voltage value does not have to been extremely accurate.
