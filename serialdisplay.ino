// bitcoin_display.ino
#include <LiquidCrystal.h>

// Initialze lcd display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Open serial port and start lcd screen
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // Check for serial data input
  if (Serial.available()) {
    // Set serial data to vars
    float buy = Serial.parseFloat();
    char end = Serial.read();
    float sell = Serial.parseFloat();

    // Display data to lcd
    lcd.clear();
    lcd.print(buy);
    lcd.setCursor(7,0);
    lcd.print("Buy");
    lcd.setCursor(0,1);
    lcd.print(sell);
    lcd.setCursor(7,1);
    lcd.print("Sell");
  }
}