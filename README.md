# Velocity Based Training Device


Richard Cavanagh
Downing College
rc755

## Project Summary

The code in this repository uses the Warp firmware and runs on the FRDM KL03Z development board. Acceleration is measured using an MMA8451Q accelerometer, integrated to obtain the velocity and displayed on an SSD1331 OLED display.


## How to use

Once the device is assembled as listed, use the velcro straps to wrap it around a barbell handle, with the OLED and FRDM board facing towards the ground. WHen ready to perform the exercise, turn on the power supply and the OLED will display a green rectangle; the device is now in measuring mode. Measuring will stop after approximately 45 seconds, or if the SW3 button is pressed. The screen will now show a graph of the velocities for each repetition throughout the set, normalised to the highest value. To start tracking again, press the reset button again, and repeat.


## Repository Layout

### src/boot/ksdk1.1.0:
Drivers for the OLED and accelerometer are stored here, with boot.c.


### doc
Contains a README for formatting and ... conventions in the repository.









Low-pass filter enabled and high-pass disabled, to smooth output. Register 0x0F: 16 Hz cut off frequency
