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

 lcd::lcd(int RSTs,int CEs,int DCs,unsigned char c) {
RST = RSTs;
CE = CEs;
DC =DCs;
contrast = c;
SPI.begin();
 SPI.setBitOrder(MSBFIRST);
SPI.setClockDivider(SPI_CLOCK_DIV8);
SPI.setDataMode(SPI_MODE3);


pinMode(RST, OUTPUT);
pinMode(CE, OUTPUT);
pinMode(DC, OUTPUT);
//pinMode(DIN, OUTPUT);
//pinMode(CLK, OUTPUT);

digitalWrite(RST, LOW);
digitalWrite(RST, HIGH); 
 
//contrast = contrast << 1 >> 1;
contrast = contrast | B10000000;

LcdDo(0x21,true);
LcdDo(contrast,true);
LcdDo(0x04,true);
LcdDo(0x14,true);
LcdDo(0x20,true);
LcdDo(0x0C,true);
clearLcd();
drawLcd();

}

 void lcd::clearLcd(){
  for (int y = 0;y<6;y++){
     for (int x = 0;x<84;x++){
      screen[x][y] = 0x00;
     }
  }
}



 void lcd::drawLcd(){


  digitalWrite(CE, LOW);
  digitalWrite(DC, LOW);
 // shiftOut(DIN, CLK, MSBFIRST, 0x21);
 //shiftOut(DIN, CLK, MSBFIRST, 0x10);
  //shiftOut(DIN, CLK, MSBFIRST, 0x40);
  //shiftOut(DIN, CLK, MSBFIRST, 0x20);
   SPI.transfer(0x21);
 SPI.transfer(0x10);
 SPI.transfer(0x40);
SPI.transfer(0x20);
  digitalWrite(DC, HIGH);
 for (int y = 0;y<6;y++){
     for (int x = 0;x<84;x++){
        SPI.transfer(screen[x][y]);
   // shiftOut(DIN, CLK, MSBFIRST,screen[x][y]);
     }
  }
  
  digitalWrite(CE, HIGH);

}



void lcd::LcdDo(char data,bool cmd)
{


  if(cmd) digitalWrite(DC, LOW);
  else digitalWrite(DC, HIGH);

digitalWrite(CE, LOW);
SPI.transfer(data);
//shiftOut(DIN, CLK, MSBFIRST, data);
digitalWrite(CE, HIGH);
}


bool lcd::getPixel(int x,int y){
  int t =  y%8;
  bool re = bitRead(screen[x][int(floor(y/8))],t);
  return re;
}

void lcd::setPixel(int x,int y,bool on){
  int t =  y%8;
  if(x < 0 || x > 83 || y < 0 || y > 47){
    return;
  }
  if (on){
  screen[x][int(floor(y/8))] = screen[x][int(floor(y/8))] | (char(B00000001 << t));
  }else{
    screen[x][int(floor(y/8))] = screen[x][int(floor(y/8))] & (char(B00000001 << t) ^ B11111111);
  }
}



void lcd::drawRect(int x1,int y1,int x2,int y2,bool fill,bool on){
  if(!fill){
  drawLine(x1,y1,x2,y1,on);
  drawLine(x1,y1,x1,y2,on);
  drawLine(x2,y1,x2,y2,on);
  drawLine(x1,y2,x2,y2,on);
  }else{
    for (int y = y1;y != y2+(y2 - y1) / abs(y2-y1);y=y+(y2 - y1) / abs(y2-y1)){
    for (int x = x1;x != x2+(x2 - x1) / abs(x2-x1);x=x+(x2 - x1) / abs(x2-x1)){
      setPixel(x,y,on);
    }
  }
  }
}


void lcd::drawCircle(int x1,int y1,int r,bool fill,bool on){
  if(x1 > 83  + r|| x1  < 0 - r|| y1 > 47  + r ||  y1 < 0  - r){
     return;
  }
  int prey = 0;
  r++;
  for (double i = 1; i < 90;i+=20.00/r + 0.01){
    int nx = cos(i *  3.14 / 180) * r;
    int ny = sin(i *  3.14 / 180) * r;
    if(fill){
     if(prey != ny + y1){
     for(int fi = nx + x1; fi > -nx + x1 - 1;fi--){
      setPixel(fi,ny + y1,on);
      setPixel(fi,-ny + y1,on);
     }
     }
     prey = ny + y1;
    }else{
    setPixel(nx + x1,ny + y1,on);
    setPixel(-nx + x1,ny + y1,on);
    setPixel(nx + x1,-ny + y1,on);
    setPixel(-nx + x1,-ny + y1,on);
    }
  }
}


void lcd::drawLine(int x1,int y1,int x2,int y2,bool on){

  if(x1 == x2){
    for(int y = y1;y != y2+(y2 - y1) / abs(y2-y1);y=y+(y2 - y1) / abs(y2-y1)){
      setPixel(x1,y,on);
    }  
  }else if(y1 == y2){
    for(int x = x1;x != x2 +(x2 - x1) / abs(x2-x1);x=x+(x2 - x1) / abs(x2-x1)){
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



