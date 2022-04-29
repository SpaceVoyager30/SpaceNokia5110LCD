/*
made by:Space_Voyager30
28/5/2017

*/


#include "SpaceNokia5110Lcd.h"
#include "Arduino.h"
#include <SPI.h>


const byte textCode[][5] PROGMEM = {
      {B01111000,B11111100,B10010100,B11111100,B01111000}, //0 null / unknown character

      {B00000000,B00000000,B00000000,B00000000,B00000000}, //32 space " "
      {B11110100}, //33 "!"
      {B11000000,B00000000,B11000000}, //34 """
      {B00101000,B01111100,B00101000,B01111100,B00101000}, //35 "#"
      {B01101000,B01101000,B11111100,B01011000,B01011000}, //36 "$"
      {B11001100,B11011000,B00110000,B01101100,B11001100}, //37 "%"
      {B01011000,B10100100,B10110100,B01001000,B00010100}, //38 "&"
      {B11000000}, //39 "'"
      {B01111000,B10000100}, //40 "("
      {B10000100,B01111000}, //41 ")"
      {B01100000,B11000000,B01100000}, //42 "*"
      {B00010000,B00010000,B01111100,B00010000,B00010000}, //43 "+"
      {B00001100}, //44 ","
      {B00010000,B00010000,B00010000,B00010000}, //45 "-"
      {B00000100}, // 46 "."
      {B00001100,B00110000,B11000000}, //47 "/"

      {B01111000,B10001100,B10110100,B11000100,B01111000}, // 48 "0"
      {B00000100,B01000100,B11111100,B00000100,B00000100},// 49 "1"
      {B01000100,B10001100,B10010100,B10010100,B01100100},// 50 "2"
      {B01001000,B10000100,B10100100,B10100100,B01011000},// 51 "3"
      {B00010000,B00110000,B01010000,B11111100,B00010000},// 52 "4"
      {B11101000,B10100100,B10100100,B10100100,B10011000},// 53 "5"
      {B01111000,B10100100,B10100100,B10100100,B00011000},// 54 "6"
      {B10000100,B10001000,B10010000,B10100000,B11000000},// 55 "7"
      {B01011000,B10100100,B10100100,B10100100,B01011000},// 56 "8"
      {B01100100,B10010100,B10010100,B10010100,B01111000},// 57 "9"

      {B00101000},// 58 ":"
      {B00101100},// 59 ";"
      {B00010000,B00101000,B01000100}, //60 "<"
      {B00101000,B00101000,B00101000,B00101000}, //61 "="
      {B01000100,B00101000,B00010000}, //62 ">"
      {B01000000,B10000000,B10010100,B10100000,B01000000}, //63 "?"
      {B01111000,B10000100,B10110100,B10110100,B01100100}, //64 "@"

      {B00001100,B01110000,B10010000,B01110000,B00001100}, //65 "A"
      {B11111100,B10100100,B10100100,B10100100,B01011000}, //66 "B"
      {B01111000,B10000100,B10000100,B10000100,B01001000}, //67 "C"
      {B11111100,B10000100,B10000100,B10000100,B01111000}, //68 "D"
      {B11111100,B10100100,B10100100,B10100100,B10000100}, //69 "E"
      {B11111100,B10100000,B10100000,B10100000,B10000000}, //70 "F"
      {B01111000,B10000100,B10000100,B10010100,B01011000}, //71 "G"
      {B11111100,B00100000,B00100000,B00100000,B11111100}, //72 "H"
      {B10000100,B10000100,B11111100,B10000100,B10000100}, //73 "I"
      {B10001000,B10000100,B10000100,B11111000,B10000000}, //74 "J"
      {B11111100,B00010000,B00101000,B01000100,B10000000}, //75 "K"
      {B11111100,B00000100,B00000100,B00000100,B00000100}, //76 "L"
      {B11111100,B01000000,B00110000,B01000000,B11111100}, //77 "M"
      {B11111100,B11000000,B00110000,B00001100,B11111100}, //78 "N"
      {B01111000,B10000100,B10000100,B10000100,B01111000}, //79 "O"
      {B11111100,B10010000,B10010000,B10010000,B01100000}, //80 "P"
      {B01111000,B10000100,B10010100,B10001100,B01111000}, //81 "Q"
      {B11111100,B10010000,B10010000,B10010000,B01101100}, //82 "R"
      {B01001000,B10100100,B10100100,B10100100,B10011000}, //83 "S"
      {B10000000,B10000000,B11111100,B10000000,B10000000}, //84 "T"
      {B11111000,B00000100,B00000100,B00000100,B11111000}, //85 "U"
      {B11000000,B00110000,B00001100,B00110000,B11000000}, //86 "V"
      {B11111000,B00000100,B00011000,B00000100,B11111000}, //87 "W"
      {B10000100,B01001000,B00110000,B01001000,B10000100}, //88 "X"
      {B10000000,B01000000,B00111100,B01000000,B10000000}, //89 "Y"
      {B10001100,B10010100,B10100100,B11000100,B10000100}, //90 "Z"

      {B11111100,B10000100}, //91 "["
      {B11000000,B00110000,B00001100}, //92 "\"
      {B10000100,B11111100}, //93 "]"
      {B00100000,B01000000,B10000000,B01000000,B00100000}, //94 "^"
      {B00000100,B00000100,B00000100,B00000100,B00000100}, //95 "_"
      {B10000000,B01000000}, //96 "`"

      {B00011000,B00100100,B00111000,B00000100}, //97 "a"
      {B11111100,B00100100,B00100100,B00011000}, //98 "b"
      {B00011000,B00100100,B00100100,B00100100}, //99 "c"
      {B00011000,B00100100,B00100100,B11111100}, //100 "d"
      {B00011000,B00110100,B00110100,B00010100}, //101 "e"
      {B00100000,B01111100,B10100000,B10100000}, //102 "f"
      {B00100100,B01010100,B01010100,B01111000}, //103 "g"
      {B11111100,B00010000,B00010000,B00001100}, //104 "h"
      {B01011100}, //105 "i"
      {B00000100,B10111100}, //106 "j"
      {B11111100,B00101000,B00101000,B00010100}, //107 "k"
      {B11111000,B00000100}, //108 "l"
      {B00111100,B00100000,B00111100,B00100000,B00011100}, //109 "m"
      {B00111100,B00100000,B00100000,B00011100}, //110 "n"
      {B00011000,B00100100,B00100100,B00011000}, //111 "o"
      {B01111100,B01010000,B01010000,B00100000}, //112 "p"
      {B00100000,B01010000,B01010000,B01111000}, //113 "q"
      {B00111100,B00100000,B00100000,B00010000}, //114 "r"
      {B00010100,B00110100,B00101100,B00101000}, //115 "s"
      {B00100000,B11111000,B00100100}, //116 "t"
      {B00111000,B00000100,B00000100,B00111100}, //117 "u"
      {B00110000,B00001100,B00110000,B00000000}, //118 "v"
      {B00111000,B00000100,B00011000,B00000100,B00111000}, //119 "w"
      {B00100100,B00011000,B00011000,B00100100}, //120 "x"
      {B01100100,B00010100,B00010100,B01111000}, //121 "y"
      {B00100100,B00101100,B00110100,B00100100}, //122 "z"

      {B00110000,B11111100,B10000100}, //123 "{"
      {B11111100}, //124 "|"
      {B10000100,B11111100,B00110000}, //125 "}"
      {B00110000,B00100000,B00010000,B00110000}, //126 "~"

      //-------------rotated 90 degrees clockwise---------------//
      {B00001000,B00100100,B00000100,B00100100,B00001000}, //127 :)
      {B00001000,B00101000,B00001000,B00101000,B00001000}, //128 :|
      {B00000100,B00101000,B00001000,B00101000,B00000100}, //129 :(
      {B00010000,B01011000,B00010100,B01010100,B00011000}, //130 :P
      {B10100100,B10101000,B01001000,B10101000,B10100100}, //131 x(
      //-------------rotated 90 degrees clockwise---------------//

      //-------------------maths-stuff--------------------------//
      {B01000000,B10100000,B01000000}, //132 "degrees symbol"
      {B00100100,B01110100,B00100100}, //133 "plus minus"
      {B10001100,B01010100,B00100100}, //134 ">="
      {B00100100,B01010100,B10001100}, //135 "<="
      {B00100000,B00111100,B00100000,B00111100,B00100000}, //136 "pi"
      {B00010000,B00010000,B01010100,B00010000,B00010000}, //137 "divide symbol"

      {B11100000,B10100000,B11100000}, //138 superscript zero
      {B11100000}, //139 superscript one
      {B10100000,B01100000,B00100000,B00000000,B00000000}, //140 superscript two
      {B10100000,B11100000,B11100000,B00000000,B00000000}, //141 superscript three
      {B01000000,B01000000,B11100000,B10100000,B11100000}, //142 superscript -zero
      {B01000000,B01000000,B00000000,B11100000}, //143 superscript -one
      {B01000000,B01000000,B10100000,B01100000,B00100000}, //144 superscript -two
      {B01000000,B01000000,B10100000,B11100000,B11100000}, //145 superscript -three

      {B00111100,B00001000,B00110000}, //146 "?"
      {B00000000,B00000000,B00000000,B00000000,B00000000}, //147
      //-------------------maths-stuff--------------------------//
      };


	  //the code from here to line 235 is part of Anon-Penguin's SpeedTrig  https://github.com/Anon-Penguin/SpeedTrig

const float SIN_TABLE[181] PROGMEM={
  0.000000, 0.008727, 0.017452, 0.026177, 0.034899, 0.043619, 0.052336, 0.061049, 0.069756, 0.078459, 0.087156, 0.095846, 0.104528,
  0.113203, 0.121869, 0.130526, 0.139173, 0.147809, 0.156434, 0.165048, 0.173648, 0.182236, 0.190809, 0.199368, 0.207912, 0.216440,
  0.224951, 0.233445, 0.241922, 0.250380, 0.258819, 0.267238, 0.275637, 0.284015, 0.292372, 0.300706, 0.309017, 0.317305, 0.325568,
  0.333807, 0.342020, 0.350207, 0.358368, 0.366501, 0.374607, 0.382683, 0.390731, 0.398749, 0.406737, 0.414693, 0.422618, 0.430511,
  0.438371, 0.446198, 0.453990, 0.461749, 0.469472, 0.477159, 0.484810, 0.492424, 0.500000, 0.507538, 0.515038, 0.522499, 0.529919,
  0.537300, 0.544639, 0.551937, 0.559193, 0.566406, 0.573576, 0.580703, 0.587785, 0.594823, 0.601815, 0.608761, 0.615661, 0.622515,
  0.629320, 0.636078, 0.642788, 0.649448, 0.656059, 0.662620, 0.669131, 0.675590, 0.681998, 0.688355, 0.694658, 0.700909, 0.707107,
  0.713250, 0.719340, 0.725374, 0.731354, 0.737277, 0.743145, 0.748956, 0.754710, 0.760406, 0.766044, 0.771625, 0.777146, 0.782608,
  0.788011, 0.793353, 0.798636, 0.803857, 0.809017, 0.814116, 0.819152, 0.824126, 0.829038, 0.833886, 0.838671, 0.843391, 0.848048,
  0.852640, 0.857167, 0.861629, 0.866025, 0.870356, 0.874620, 0.878817, 0.882948, 0.887011, 0.891007, 0.894934, 0.898794, 0.902585,
  0.906308, 0.909961, 0.913545, 0.917060, 0.920505, 0.923880, 0.927184, 0.930418, 0.933580, 0.936672, 0.939693, 0.942641, 0.945519,
  0.948324, 0.951057, 0.953717, 0.956305, 0.958820, 0.961262, 0.963630, 0.965926, 0.968148, 0.970296, 0.972370, 0.974370, 0.976296,
  0.978148, 0.979925, 0.981627, 0.983255, 0.984808, 0.986286, 0.987688, 0.989016, 0.990268, 0.991445, 0.992546, 0.993572, 0.994522,
  0.995396, 0.996195, 0.996917, 0.997564, 0.998135, 0.998630, 0.999048, 0.999391, 0.999657, 0.999848, 0.999962, 1.000000
};


float lcd::fsin(int deg) {
  deg *= 10;
  float result = 0;
  int sign = 1;

  if (deg < 0) {
    deg = -deg;
    sign = -1;
  }

  while(deg >= 3600) {
    deg -= 3600;
  }

  if((deg > 0) && (deg <= 900)) {
    //0 and 90 degrees.
    result = pgm_read_float(&(SIN_TABLE[deg / 5]));

  } else if((deg > 900) && (deg <= 1800)) {
    //90 and 180 degrees.
    result = pgm_read_float(&(SIN_TABLE[(1800 - deg) / 5]));

  } else if((deg > 1800) && (deg <= 2700)) {
    //180 and 270 degrees.
    result = -pgm_read_float(&(SIN_TABLE[(deg - 1800) / 5]));

  } else if((deg > 2700) && (deg <= 3600)) {
    //270 and 360 degrees.
    result = -pgm_read_float(&(SIN_TABLE[(3600 - deg) / 5]));

  }
  return sign * result;
}

float lcd::fcos(int deg) {
  deg *= 10;
  float result = 0;
  if (deg < 0) {
    deg = -deg;
  }

  while(deg >= 3600) {
    deg -= 3600;
  }

  if((deg >= 0) && (deg <= 900)) {
    //0 and 90 degrees.
    result = pgm_read_float(&(SIN_TABLE[(900 - deg) / 5]));

  } else if((deg > 900) && (deg <= 1800)) {
    //90 and 180 degrees.
    result = -pgm_read_float(&(SIN_TABLE[(deg - 900) / 5]));

  } else if((deg > 1800) && (deg <= 2700)) {
    //180 and 270 degrees.
    result = -pgm_read_float(&(SIN_TABLE[(2700 - deg) / 5]));

  } else if((deg >= 2700) && (deg <= 3600)) {
    //270 and 360 degrees.
    result = pgm_read_float(&(SIN_TABLE[(deg - 2700) / 5]));

  }
  return result;
}


lcd::lcd(int RSTs,int CEs,int DCs,unsigned char c) {
  RST = RSTs;
  CE = CEs;
  DC =DCs;
  contrast = c;

  SPI.setBitOrder(MSBFIRST);

  #if defined(ESP8266)
  SPI.setFrequency(4000000);
  #else
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  #endif
  SPI.begin();

  pinMode(RST, OUTPUT);
  pinMode(CE, OUTPUT);
  pinMode(DC, OUTPUT);

  digitalWrite(RST, LOW);
  digitalWrite(RST, HIGH);

  //contrast = contrast << 1 >> 1;
  contrast = contrast | B10000000;

  lcdDo(0x21,true);     //switch to extended instruction set
  lcdDo(contrast,true); //set contrast(write VOP to register)
  lcdDo(0x04,true);     //set Temperature Coefficient to 0
  lcdDo(0x10,true);     //set Bias System (BSx) to 0
  lcdDo(0x20,true);     //switch to basic instruction set
  lcdDo(0x0C,true);
  clearLcd();
  drawLcd();
}


void lcd::clearLcd(){ //sets all pixels in  frame buffer ot off
  for (int i = 0;i<504;i++){
    frameBuffer[i] = 0;
  }
}


void lcd::drawLcd(){
  #if defined(ESP8266)
      ESP.wdtFeed();
  #endif
  digitalWrite(CE, LOW);
  digitalWrite(DC, LOW);
  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
  SPI.transfer(0x20);
  SPI.transfer(0x40);
  SPI.transfer(0x80);
  digitalWrite(DC, HIGH);
  for(int i = 0;i < 504;i++){
    SPI.transfer(frameBuffer[i]);
  }
  SPI.endTransaction();
  digitalWrite(CE, HIGH);
}



void lcd::lcdDo(char data,bool cmd)
{
  #if defined(ESP8266)
  	  ESP.wdtFeed();
  #endif
  if(cmd) digitalWrite(DC, LOW);
  else digitalWrite(DC, HIGH);
  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
  digitalWrite(CE, LOW);
  SPI.transfer(data);
  digitalWrite(CE, HIGH);
  SPI.endTransaction();
}


bool lcd::getPixel(int x,int y){
  return bitRead(frameBuffer[(y / 8) * 84 + (x % 84)], y % 8);
}

void lcd::setPixel(int x,int y,bool on){
  int t =  y%8;
  if(x < 0 || x > 83 || y < 0 || y > 47){
    return;
  }
  if (on){
    frameBuffer[(y / 8) * 84 + (x % 84)] = frameBuffer[(y / 8) * 84 + (x % 84)] | (char(B00000001 << t));
    return;
  }
  frameBuffer[(y / 8) * 84 + (x % 84)] = frameBuffer[(y / 8) * 84 + (x % 84)] & (char(B00000001 << t) ^ B11111111);
}



void lcd::drawRect(int x1,int y1,int x2,int y2,bool fill,bool on){
  if(!fill){ //If the rectangle is hollow
    if(x1 != x2){
    drawLine(x1,y1,x1,y2,on);
    drawLine(x2,y1,x2,y2,on);
    }
    if(y1 != y2){
    drawLine(x1,y1,x2,y1,on);
    drawLine(x1,y2,x2,y2,on);
    }
    return;
  }
  if(y1 != y2 && x1 != x2){ //If the rectangle is filled
    if(y1>y2){
      int t = y1;
      y1 = y2;
      y2 = t;
    }
    if(x1>x2){
      int t = x1;
      x1 = x2;
      x2 = t;
    }
    for(int y = y1;y < y2+1;y++){
      for(int x = x1;x < x2+1;x++){
        setPixel(x,y,on);
      }
    }
  }
}


void lcd::drawCircle(int xPosition,int yPosition,unsigned int radius,unsigned int thickness,bool on){
  radius++;
  if(thickness > radius) thickness = radius; //this pervents the circle from disappearing
  for(int xCurrent = radius; xCurrent >= 0;xCurrent--){
    for(int yCurrent = radius; yCurrent >= 0;yCurrent--){
      int squaredPositions = (xCurrent * xCurrent) + (yCurrent * yCurrent); //centered around (0,0)
      if(squaredPositions < radius * radius && (radius - thickness) * (radius - thickness) <= squaredPositions){ //would do ^2 but this is faster
        setPixel(xPosition + xCurrent, yPosition + yCurrent,on);  //mirroring around the x and y axis of the circle with offset
        setPixel(xPosition - xCurrent, yPosition + yCurrent,on);
        setPixel(xPosition + xCurrent, yPosition - yCurrent,on);
        setPixel(xPosition - xCurrent, yPosition - yCurrent,on);
      }
    }
  }
}


void lcd::drawLine(int x1,int y1,int x2,int y2,bool on){
  if(x1 == x2 && y1 == y2){
  	  setPixel(x1,y1,on);
	  return;
  }
  if(x1 == x2){
 	   if(y1>y2){
			int t = y1;
			y1 = y2;
			y2 = t;
		}
    for(int y = y1;y < y2+1;y++){
      setPixel(x1,y,on);
    }
  }else if(y1 == y2){
  	   if(x1>x2){
			int t = x1;
			x1 = x2;
			x2 = t;
		}
    for(int x = x1;x < x2+1;x++){
     setPixel(x,y1,on);
    }
  }else{
    if(abs(x2-x1) > abs(y2-y1)){
    for (int x = x1;x != x2+(x2 - x1) / abs(x2-x1);x=x+(x2 - x1) / abs(x2-x1)){
      setPixel(x,map(x,x1-(x2 - x1) / abs(x2-x1),x2,y1,y2),on);
    }
    }else{
      for (int y = y1;y != y2+(y2 - y1) / abs(y2-y1);y=y+(y2 - y1) / abs(y2-y1)){
      setPixel(map(y,y1-(y2 - y1) / abs(y2-y1),y2,x1,x2),y,on);
    }
    }
  }
}

void lcd::drawBitmap(int x1,int y1,char bitm[],int arraysize,int sx,bool overl){
  for(int i = 0;i < arraysize;i++){
    int xpart = i * 8 % sx;
    for(int p = 0; p < 8;p++){
      if(bitRead(bitm[i],7-p) == 1){
        setPixel(x1 + xpart + p % sx,y1 + (i * 8/sx),true);
      }else{
        if(overl){
        setPixel(x1 + xpart + p % sx,y1 + (i * 8/sx),false);
        }
      }
    }
  }
}

void lcd::setCursorPos(int x,int y){
  cxpos = x;
  cypos = y;
}

void lcd::drawChar(unsigned char c,bool big,bool on, bool wrap){
  drawText(String((char)c),big,on,wrap);
}
void lcd::drawText(String text,bool big,bool on, bool wrap){
  int lp = 0;
  int ep = 0;
  int x = cxpos;
  int y = cypos;
  for(int i = 0;i < text.length();i++){
    int g = text[i]; //(unsigned char)text.charAt(i);
    g -= 31;
   if(g < -30){
       g +=256;
    }
    if(g < 1 || g > sizeof(textCode) / sizeof(textCode[0])){
      if(g != -21){
         g = 0;
      }
    }
    if(!big && wrap){
       if(x + lp > 78){
          x = cxpos = 0;
          lp = 0;

          y = cypos = y + 7;
       }
    }else if (x + lp > 78/2 && wrap){
       x = cxpos = 0;
       lp = 0;
       y = cypos = y + 14;

    }
    if(g != -21){
    for(int a = 0;a < 5;a++){
      byte tCode = pgm_read_byte(&(textCode[g][a]));
      if(tCode == 0 && g != 1){
        ep++;
      }else{
      for(int i3 = 0;i3 < 6;i3++){

        if (bitRead(tCode,7-i3) == 1){
          if(big){
            setPixel(x + lp * 2,y + i3 * 2,on);
            setPixel(x + lp * 2 +1,y + i3 * 2,on);
            setPixel(x + lp * 2,y + i3 * 2 +1,on);
            setPixel(x + lp * 2 +1,y + i3 * 2+1,on);
          }else{
         setPixel(x + lp,y + i3,on);
          }
        }
      }
      }
      lp++;
      if(ep == 2){
        ep = 0;
        lp-=2;

      }
      if( ep ==1 && a == 4){
        ep = 0;
        lp-=1;
        a = 100;
      }
    }

    lp++;

  }else{
    if(!big){
          x = cxpos;
          lp = 0;

          y = cypos = y + 7;
    }else{
       x = cxpos;
        lp = 0;
        y = cypos = y + 14;
      }
    }
  }
  if(big){
    cxpos = x + lp * 2;
   }else{
  cxpos = x + lp;
   }
  cypos = y;
}
