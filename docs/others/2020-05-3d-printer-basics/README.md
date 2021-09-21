# 3D Printer basics

*Modified 2020-05-02*

TOC

- [3D Printer basics](#3d-printer-basics)
  - [Overview](#overview)
  - [Software](#software)
    - [3D Printer Slicer Software](#3d-printer-slicer-software)
    - [Other software](#other-software)
  - [Calibration](#calibration)
    - [Bed leveling](#bed-leveling)

## Overview

Work in progress..

- Different printers, How they works, CAD software, From Design to the printed detail and assembly

## Software

### 3D Printer Slicer Software

- [Ultimaker Cura](https://ultimaker.com/software/ultimaker-cura)
- [PrusaSlicer](https://www.prusa3d.com/prusaslicer/) Which is my preferred choice of using. Configurations:
  - Default profiles works like charm
  - Start G-code
  
    ```gcode
    M140 S[first_layer_bed_temperature] ;Set bed temp
    M190 S[first_layer_bed_temperature] ;Wait for bed temp
    M104 S[first_layer_temperature] ;Set extruder temp
    M109 S[first_layer_temperature] ;Wait for extruder temp
    G28 ;Home
    G1 Y0.0 X3.0 F4000.0 ;Go outside print area
    G1 Z0.2 F300.0;
    G92 E0 ;Reset Extruder
    G1 Z2.0 F3000 ;Move Z Axis up
    G1 X10.1 Y20 Z0.28 F5000.0 ;Move to start position
    G1 X10.1 Y200.0 Z0.28 F1500.0 E15 ;Draw the first line
    G1 X10.4 Y200.0 Z0.28 F5000.0 ;Move to side a little
    G1 X10.4 Y20 Z0.28 F1500.0 E30 ;Draw the second line
    G92 E0 ;Reset Extruder
    ```

  - End G-code

    ```gcode
    M104 S0 ;Turn-off hotend
    M140 S0 ;Turn-off bed
    G28 X0  ;Home X axis
    M84     ;Disable motors
    ```

  - Creality Ender 3 Bed / Build plate for PrusaSlicer, ``Ender3bed2.STL`` [thing:3866611](https://www.thingiverse.com/thing:3866611)

### Other software

- [Printrun](https://www.pronterface.com/) - 3D printing host software suite
which talks to your printer and handles the printing process.

## Calibration

Useful guidelines for calibrating the 3D Printer.

Summary of calibration files: [thing:4331621](https://www.thingiverse.com/thing:4331621) (Creality Ender 3)

### Bed leveling

The videos below provides guidelines for calibrating printer's bed.

| [![ENDER 3- Easy Way To Level Your Bed](https://img.youtube.com/vi/_EfWVUJjBdA/0.jpg)](https://www.youtube.com/watch?v=_EfWVUJjBdA) | [![Simple, Fool-Proof Bed Leveling](https://img.youtube.com/vi/RJC7N4Vb9AY/0.jpg)](https://www.youtube.com/watch?v=RJC7N4Vb9AY) |
|:---:|:---:|

Collection of files used to get job done.

| N   | Name | Link | Description |
|:---:|:-----|:-----|:------------|
| 1   | ``CHEP_ender_3_bed_level.gcode`` | [thing:3235018](https://www.thingiverse.com/thing:3235018)       | Does not use filament,  adjust each corner by running a piece of paper  |
| 2   | ``CHEP_bed_level_test.gcode``    | [thing:3235018](https://www.thingiverse.com/thing:3235018)       | Draws squares to check the calibration |
| 3   | ``bedlevel_cross.stl``           | [thing:4275680](https://www.thingiverse.com/thing:4275680/files) | You can start this print and adjust the bed when the print is running, check whatever the filament stick on the bed |
| 4   | ``xyzCalibration_cube.stl``      | [thing:1278865](https://www.thingiverse.com/thing:1278865/files) | XYZ Calibration cube, check the quality of the print for all the directions |
