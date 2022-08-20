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
  - [WIP](#wip)
    - [Octoprint plugins](#octoprint-plugins)
    - [Troubleshooting](#troubleshooting)

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

## WIP

### Octoprint plugins

https://plugins.octoprint.org/plugins/filemanager/
https://github.com/imrahil/OctoPrint-PrintHistory
https://github.com/jneilliii/OctoPrint-UltimakerFormatPackage


### Troubleshooting

[(HOW) I fixed the Ugly Layers on my 3D Printer](https://www.youtube.com/watch?v=a3oQy6v3MrA&t=236s)

[How to STOP Elephant's Foot on your 3D Prints](https://www.youtube.com/watch?v=zlgR3rHg4p8)

[3D Printing Troubleshooting Guide: Elephants Foot](https://www.youtube.com/watch?v=41vyNWlE-J4)

[3D Printer Trouble Shooting Guide](https://www.youtube.com/watch?v=rj0wpGE3uzc&list=PLfzz3f4EgsrRoSc7CIS6mZv88O2H8s44b)

[Elephant Foot Compensation](https://www.youtube.com/watch?v=U7X0DdZPses)

[https://howto3dprint.net/4-easy-ways-to-fix-3d-printing-elephant-foot/](https://howto3dprint.net/4-easy-ways-to-fix-3d-printing-elephant-foot/)

[Upgrade Creality Ender 3 with Capricorn PTFE Tubing](https://www.youtube.com/watch?v=8VmlZniuSa4)
A good video describes how to change the ptfe tube correct

[Fix Your Creality Ender 3 with New PTFE Tubing](https://www.youtube.com/watch?v=DB5b4673GJ0)

[Creality Hot End maintenance, Nozzle change, Coupling and Bowden Tube (PTFE) upgrade to Capricorn](https://www.youtube.com/watch?v=rFUUWNlJv94)

https://www.youtube.com/watch?v=kG_YKeJDaX8

[Creality Ender 3, CR-10 - Hotend PTFE Fix](https://www.youtube.com/watch?v=Fb4XMbZ0iA4)


[The Biggest Pain In 3D Printing - Hotend Clogs & Jams](https://www.youtube.com/watch?v=fzWj6adWc-Y)

Dual Drive Gear Extruder Upgrade + E Steps on Creality Ender 3
https://www.youtube.com/watch?v=QnrH2Sk7y40


[Ender 3 (Pro) Z Offset: How to Adjust It](https://all3dp.com/2/ender-3-pro-z-offset/?fbclid=IwAR1q4cy2527BHctpUqSJxOGZOB8mHnSU5PPx-4NrCwRA-8M_ORPQk6vWuvA)


[Adjusting the X-Axis on the Ender 3](http://www.mystoopidstuff.com/blog/adjusting-the-x-axis-on-the-ender-3)


[How to setup OctoPrint! (+ best plugin recommendations)](https://www.youtube.com/watch?v=HBd0olxI-No)