# Velocity Based Training Device

Richard Cavanagh
Downing College
rc755

## Project Summary

The code in this repository is based on the Warp firmware, but with several changes, and runs on the FRDM KL03Z development board. Acceleration is measured using an MMA8451Q accelerometer, integrated to obtain the velocity and displayed on an SSD1331 OLED display.


## How to use
Use a CR2032 cell to power the device through the 3V3 input. See 'FRDM-KL03Z User’s Guide' online for the FRDM port diagram.

Once the device is assembled as listed, use the velcro straps to wrap it around a barbell handle, with the OLED and FRDM board facing towards the ground. WHen ready to perform the exercise, turn on the power supply and the OLED will display a green rectangle; the device is now in measuring mode. Measuring will stop after approximately 45 seconds, or if the SW3 button is pressed. The screen will now show a graph of the velocities for each repetition throughout the set, normalised to the highest value. To start tracking again, press the reset button again, and repeat.

To improve the efficiency of measurements, try to keep the barbell still at the bottom of the rep for approximately 1 second, and try to lower the weight slowly in the eccentic phase.


## Repository Layout

### src/boot/ksdk1.1.0:
Drivers for the OLED and accelerometer are stored here, with boot.c. All the significant code that was changed from the original Warp firmware is in this folder.

## Setting up firmware

To set up the firmware, follow the instructions in the Readme at https://github.com/physical-computation/Warp-firmware, up to and including step 3.









