#include <LiquidCrystall_I2C.h>

const int col = 16;
const int row = 2;
LiquidCyrstal_I2C lcd(0x27, col, row);

int position = 0;
 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  lcd.clear();
  lcd.setCursor(position, 0);
  lcd.print("Hello, World!!!");
  lcd.setCursor(position, 1);
  lcd.print("Lenss"):
  position += 1

  if(postion < 0 || position >= col) {
    position = 0;
  }

  delay(500);
}
