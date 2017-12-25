# SpaceNokia5110LCD Library

Now works with ESP8266-12

library for Arduino and esp8266-12 to control Nokia 5110 LCD using hardware SPI

LCD pins using an arduino:

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


LCD pins using an esp8266 12e wemos D1:

1.RST -- to any pin(not SPI pins)

2.CE  -- to any pin(not SPI pins)

3.DC  -- to any pin(not SPI pins)

4.DIN -- to SPI MOSI(pin D11)

5.CLK -- to SPI SCK(pin D13)

6.VCC -- to 3.3V

7.Light -- to GND or 3.3V(on,off)

8.GND -- to GND

should work with other esp8266 boards that have hardware SPI
