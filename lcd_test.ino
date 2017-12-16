#include <SpaceNokia5110Lcd.h>

lcd lcd(8,9,10);

//for command reference please see commands.txt in the libraries folder

void setup() {
  lcd.clearLcd();
  lcd.drawText("Hello World!",true);
  lcd.drawLcd();
}

void loop() {
  

}
