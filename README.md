# SpaceNokia5110LCD Library
library for Arduino to control Nokia 5110 LCD using hardware SPI

LCD pins:
Pins 1-5 to arduino with 10K resistor or 5v to 3.3v logic level converter(for 5V arduinos)
1.RST -- to any pin(not SPI pins)
2.CE  -- to any pin(not SPI pins)
3.DC  -- to any pin(not SPI pins)
4.DIN -- to SPI MOSI(pin 11)
5.CLK -- to SPI SCK(pin 13)
6.VCC -- to 3.3V
7.Light -- to GND or 3.3V(on,off)
8.GND -- to GND
  
May work with 5V but I have not tested it(I don't recommended it)

Drawing to LCD takes < 3ms when draw text to sreen :)
big circles are slow
