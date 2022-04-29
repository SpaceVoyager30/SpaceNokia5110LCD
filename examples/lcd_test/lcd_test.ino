#include <SpaceNokia5110Lcd.h>

#if defined(ESP8266)
lcd lcd(D2,D3,D4);
#else
lcd lcd(8,9,10);
#endif
//this display runs on 3.3v


//-------------------------------------------------------------------
//For arduino's
//connect pins thought level shifter or 10k resistor on 5V arduinos
//reset(RST) on pin 8
//chip select(CE) on pin 9
//data/commands(DC) on pin 10
//data in(DIN) on pin 11
//serial clock(CLK) on pin 13
//VCC to 3.3V
//GND to GND

//-------------------------------------------------------------------
//For WeMos D1 r1 esp8266's
//connect pins directly due to the esp's being 3.3v
//reset(RST) on pin D2
//chip select(CE) on pin D3
//data/commands(DC) on pin D4
//data in(DIN) on pin D11
//serial clock(CLK) on pin D13
//VCC to 3.3V
//GND to GND

//For other esp8266 boards
//connect:
//reset(RST) on pin any GPIO that is not SPI(e.g.SCK,MOSI,MISO) and state it in the:lcd lcd(reset pin,chip enable pin,data / command pin)
//chip select(CE) on pin ^^
//data/commands(DC) on pin ^^
//data in(DIN) on pin D11 or the main MOSI pin
//serial clock(CLK) on pin D13 or the main SCK
//VCC to 3.3V
//GND to GND


//to use back light connect "Light" pin to GND


//for command reference, please see commands.txt in the libraries folder
void setup() {

 // Serial.begin(115200);
  lcd.clearLcd();
  lcd.setCursorPos(0,0);
  lcd.drawText("Hello\nWorld!",true);
  lcd.drawLcd();
  delay(1000);
 randomSeed(analogRead(A0));

  lcd.clearLcd();
  lcd.setCursorPos(0,0);
  for(int i = 31;i < 147;i++){

    lcd.drawChar(i);
    lcd.drawLcd();
    delay(5);
  }

  delay(3000);

    lcd.clearLcd();
  lcd.setCursorPos(0,0);
  for(int i = 0;i < 48;i+=2){

    lcd.drawCircle(84/2,48/2,i,1);
    lcd.drawLcd();
    delay(5);
  }



      lcd.clearLcd();
  lcd.setCursorPos(0,0);
  for(int i = 48;i > -1;i-=2){

    lcd.drawCircle(84/2,48/2,i,-1,i % 4 == 0);
    lcd.drawLcd();
    delay(5);
  }


  delay(1000);
    lcd.clearLcd();
  lcd.setCursorPos(0,0);

  for(int i = 0;i < 48;i+=2){

    lcd.drawRect(84/2 - i,48/2 - i,84/2 + i,48/2 + i,false);

    lcd.drawLcd();

    delay(25);
  }



      lcd.clearLcd();
  lcd.setCursorPos(0,0);
  for(int i = 48;i > 0;i-=2){

    lcd.drawRect(84/2 - i,48/2 - i,84/2 + i,48/2 + i,true,i % 4 == 0);
    lcd.drawLcd();
    delay(5);
  }
  delay(1000);
  int pery = 0;
    for(int i = 0;i < 500;i++){
            lcd.clearLcd();
      for(int w = 1; w < 84;w++){
        //lcd.setPixel(w,24 + lcd.fsin(radians(i + (w* 5)))*20);
        int sr = 24 + lcd.fsin(i + (w * i / 10))*20;
        lcd.drawLine(w-1,pery,w, sr);
        pery = sr;
      }
     lcd.drawLcd();

    }
    lcd.drawLine(0,0,0,47,false);
    for(int i = 0;i< 48;i++){
    int y = random(0,48);
    if(lcd.getPixel(0,y) == 1){
      i--;
    }else{
      for(int w = 0; w < 84; w++){
        lcd.setPixel(w,y);
        lcd.drawLcd();
      }
    }
   }

  for(int i = 0;i < 84;i++){
    int x = random(0,84);
    if(lcd.getPixel(x,0) == 0){
      i--;
    }else{
      for(int w = 0; w < 48; w++){
        lcd.setPixel(x,w,false);
        lcd.drawLcd();
      }
    }
  }

  char thu[] = {
    B00000000,B01000000,
    B00000000,B10100000,
    B00000000,B10100000,
    B00000001,B00100000,
    B00000010,B00100000,
    B00000100,B01000000,
    B00011000,B01000000,
    B11100000,B01111100,
    B11100000,B00000010,
    B11100000,B00011100,
    B11100000,B00000010,
    B11100000,B00011100,
    B11100000,B00000010,
    B11100000,B00011100,
    B11111110,B00000100,
    B00000001,B11111000,
  };
  lcd.drawBitmap(84/2-8,48/2-8,thu,sizeof(thu),16);
  lcd.drawLcd();
   delay(2000);
   for(int i = 0;i < 360*4;i++){
    lcd.clearLcd();
    lcd.drawBitmap(84/2-8 + (cos(radians(i))) * 30,48/2-8 + (lcd.fsin(i)) * 15,thu,sizeof(thu),16);
    lcd.drawLcd();
   }
   for(int i = 0;i < 360*2;i++){
    lcd.clearLcd();
    lcd.drawBitmap(84/2-8 + (cos(radians(i))) * 30,48/2-8 + (lcd.fsin(i)) * 15,thu,sizeof(thu),16);
    lcd.drawBitmap(84/2-8 + (cos(radians(i+180))) * 30,48/2-8 + (lcd.fsin(i+180)) * 15,thu,sizeof(thu),16);
    lcd.drawLcd();
   }


  char space[] = {
    B00010000,B01000000,
    B00001000,B10000000,
    B00011111,B11000000,
    B00110111,B01100000,
    B01111111,B11110000,
    B01011111,B11010000,
    B01010000,B01010000,
    B00001101,B10000000,
  };

  lcd.clearLcd();
  lcd.drawBitmap(84/2-6,15,space,sizeof(space),16);
  lcd.drawLcd();

  for(int i = 48;i>20;i--){
  lcd.clearLcd();
  lcd.drawBitmap(84/2-6,15,space,sizeof(space),16);
  lcd.drawRect(84/2-1,i,84/2+1,i - 6);
  lcd.drawLcd();
  delay(20);
  }
  float pars[15][2];
  float parsv[15][2];
  int parsize[15];
  for(int i = 0;i < 15;i++){
    pars[i][0] = 84/2;
    pars[i][1] = 18;
    parsize[i] = random(1,4);
    parsv[i][0] = (random(4000)-2000)/1000.00f / parsize[i];
    parsv[i][1] = -random(4000)/1000.00f / parsize[i];
  }
  lcd.clearLcd();
  while (true){
    lcd.clearLcd();
    for(int i = 0;i < 10;i++){
      pars[i][0] += parsv[i][0];
      pars[i][1] += parsv[i][1];
      if(pars[i][0] - parsize[i] < 0){
        parsv[i][0] *= -0.95f;
        pars[i][0]++;
        }
      if(pars[i][0] + parsize[i] > 83){
        parsv[i][0] *= -0.95f;
        pars[i][0]--;
      }
      if(pars[i][1] - parsize[i] < 0){
        parsv[i][1] *= -0.95f;
        pars[i][1]++;
        }
      if(pars[i][1] + parsize[i] > 47){
        parsv[i][1] *= -0.95f;
        pars[i][1]--;
      }
      lcd.drawCircle(pars[i][0],pars[i][1],parsize[i],-1);
    }
    lcd.drawLcd();
    delay(10);
  }
}

void loop(){

}
