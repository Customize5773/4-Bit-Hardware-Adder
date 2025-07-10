#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27, 16x2 display

// Hardware connections for 74LS83 4-bit adder
const int SUM_BITS[] = {A0, A1, A2, A3};  // S0-S3 outputs from 74LS83
const int CARRY_OUT = A4;                 // C4 output from 74LS83

// 7-segment display pins (connected to 74LS47 decoder)
const int SEGMENT_PINS[] = {7, 8, 9, 10, 11, 12, 13};  // a-g pins

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  // Set adder output pins as inputs
  for (int i = 0; i < 4; i++) {
    pinMode(SUM_BITS[i], INPUT);
  }
  pinMode(CARRY_OUT, INPUT);
  
  // Set 7-segment pins as outputs (for direct control if needed)
  for (int i = 0; i < 7; i++) {
    pinMode(SEGMENT_PINS[i], OUTPUT);
    digitalWrite(SEGMENT_PINS[i], HIGH);  // Default OFF
  }
  
  lcd.print("4-Bit Adder v1.0");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read 4-bit sum and carry
  int sum_value = 0;
  for (int i = 0; i < 4; i++) {
    sum_value |= (digitalRead(SUM_BITS[i]) << i);
  }
  bool carry = digitalRead(CARRY_OUT);
  
  // Calculate total value (including carry)
  int total_value = sum_value + (carry ? 16 : 0);
  
  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("A+B: ");
  lcd.print(total_value);
  lcd.print(" (");
  lcd.print(carry ? "C1 " : "C0 ");
  printBinary(sum_value);
  lcd.print(")");
  
  lcd.setCursor(0, 1);
  lcd.print("Dec: ");
  lcd.print(total_value);
  lcd.print(" Bin: ");
  printBinary(sum_value);
  
  delay(500);  // Update delay
}

// Helper function to print binary values
void printBinary(int value) {
  for (int i = 3; i >= 0; i--) {
    lcd.print(bitRead(value, i));
  }
}
