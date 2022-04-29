#ifndef SpaceNokia5110Lcd_h
#define SpaceNokia5110Lcd_h

#include "Arduino.h"
#include "SPI.h"

class lcd
{
  public:
    lcd(int RSTs,int CEs,int DCs,unsigned  char c = 80);
    void clearLcd();
    void drawLcd();
    void lcdDo(char data,bool cmd);
    void setPixel(int x,int y,bool on = true);
    bool getPixel(int x,int y);
    void drawRect(int x1,int y1,int x2,int y2,bool fill = true,bool on = true);
    void drawCircle(int xPosition,int yPosition,unsigned int radius,unsigned int thickness = -1,bool on = true);
    void drawLine(int x1,int y1,int x2,int y2,bool on = true);
    void drawBitmap(int x1,int y1,char bitm[],int arraysize,int sx,bool overl = false);
    void setCursorPos(int x,int y);
    void drawChar(unsigned char c,bool big = false,bool on = true, bool wrap = true);
    void drawText(String text,bool big = false,bool on = true, bool wrap = true);

    float fsin(int deg) ;
    float fcos(int deg) ;
    int cxpos = 0;
    int cypos = 0;

    int RST;
    int CE;
    int DC;
    unsigned char frameBuffer[504] = {};
  private:
    unsigned char c;
    unsigned char contrast;//B01010000
    char data;
    bool temp;
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
    bool re;
    char bitm[];
};
#endif
