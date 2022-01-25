# Velocity Based Training Device


Richard Cavanagh
Downing College
rc755

## Project Summary

The code in this repository uses the Warp firmware and runs on the FRDM KL03Z development board. Acceleration is measured using an MMA8451Q accelerometer, integrated to obtain the velocity and displayed on an SSD1331 OLED display.

## Repository Layout

### src/boot/ksdk1.1.0:
Drivers for the OLED and accelerometer are stored here, with boot.c.


### doc
Contains a README for formatting and ... conventions in the repository.









Low-pass filter enabled and high-pass disabled, to smooth output. Register 0x0F: 16 Hz cut off frequency
