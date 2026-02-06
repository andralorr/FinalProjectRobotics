#include <LiquidCrystal.h>
#include "Config.h"
#include "InputController.h"
#include "LcdRenderer.h"
#include "GameEngine.h"

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
InputController input;
LcdRenderer renderer(&lcd);
GameEngine engine(&input, &renderer);

void setup() {
  lcd.begin(16, 2);
  delay(100);
  engine.init();
}

void loop() {
  engine.update();
}
