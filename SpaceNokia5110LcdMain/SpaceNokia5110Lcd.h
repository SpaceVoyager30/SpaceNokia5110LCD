#ifndef SpaceNokia5110Lcd_h
#define SpaceNokia5110Lcd_h 

#include "Arduino.h"
#include "SPI.h"


class lcd
{
  public:
   lcd(int RSTs,int CEs,int DCs,unsigned  char c);
      void clearLcd();
      void drawLcd();
      void LcdDo(char data,bool cmd);
      void setPixel(int x,int y,bool on);
      void drawRect(int x1,int y1,int x2,int y2,bool on,bool fill);
      void drawCircle(int x1,int y1,int r,bool on,bool fill);
      void drawLine(int x1,int y1,int x2,int y2,bool on);
      void drawBitmap(int x1,int y1,char bitm[],int arraysize,int sx,bool overl);
     void setCursorPos(int x,int y);
    void drawChar(char c,bool on,bool big);
    void drawText(String text,bool on,bool big);
    int cxpos = 0;
    int cypos = 0;

     int RST;
     int CE;
     int DC;
    private:
unsigned char c;
   unsigned char contrast;//B01010000
    unsigned char screen[84][6] = {};
    char data;
   char bitm[];
    int x;
    int y;
    int x1;
    int x2;
    int y1;
    int y2;
    bool on;
    bool fill;
    bool overl;
    int lp = 0;
    int ep = 0;
    unsigned char g;
};
#endif