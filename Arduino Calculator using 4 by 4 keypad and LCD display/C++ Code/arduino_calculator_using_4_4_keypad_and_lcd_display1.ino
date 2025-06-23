
// Include necessary libraries
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

// Initialize the LCD screen with the Arduino pins it's connected to
// Format: LiquidCrystal(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Variables to hold the numbers and the result
long first = 0;
long second = 0;
double total = 0;
char customKey;

// Define the keypad layout (rows and columns)
const byte ROWS = 4;
const byte COLS = 4;

// Define the keymap which corresponds to the keypad layout
// 'C' is for Clear, '#' is for Equals
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '#', '/'}
};

// Define the Arduino pins connected to the keypad rows and columns
byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 1, 0};

// Create a Keypad object
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Function to get the second number from the keypad
long getSecondNumber() {
  long num = 0;
  while (1) {
    customKey = customKeypad.getKey();
    if (customKey) { // Proceed if a key is pressed
      if (customKey >= '0' && customKey <= '9') {
        num = num * 10 + (customKey - '0');
        lcd.print(customKey); // Display the digit pressed
      }
      if (customKey == '#') { // If '#' (equals) is pressed, exit the loop
        break;
      }
    }
  }
  return num;
}

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Calculator");
  lcd.setCursor(0, 1);
  lcd.print("Enter numbers");
  delay(2000); // Display welcome message for 2 seconds
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  customKey = customKeypad.getKey();

  if (customKey) { // Proceed only if a key is pressed
    switch (customKey) {
      // Handle numeric keys (0-9) for the first number
      case '0' ... '9':
        first = first * 10 + (customKey - '0');
        lcd.setCursor(0, 0);
        lcd.print(first);
        break;

      // Handle the addition operation
      case '+':
        lcd.print('+');
        second = getSecondNumber();
        total = first + second;
        lcd.setCursor(0, 1); // Move cursor to the second line for the result
        lcd.print(total);
        first = 0;
        second = 0;
        break;

      // Handle the subtraction operation
      case '-':
        lcd.print('-');
        second = getSecondNumber();
        total = first - second;
        lcd.setCursor(0, 1);
        lcd.print(total);
        first = 0;
        second = 0;
        break;

      // Handle the multiplication operation
      case '*':
        lcd.print('*');
        second = getSecondNumber();
        total = first * second;
        lcd.setCursor(0, 1);
        lcd.print(total);
        first = 0;
        second = 0;
        break;

      // Handle the division operation
      case '/':
        lcd.print('/');
        second = getSecondNumber();
        lcd.setCursor(0, 1);
        if (second == 0) {
          lcd.print("Invalid Div"); // Handle division by zero
        } else {
          total = (float)first / (float)second; // Use float for decimal results
          lcd.print(total);
        }
        first = 0;
        second = 0;
        break;

      // Handle the Clear function
      case 'C':
        first = 0;
        second = 0;
        total = 0;
        lcd.clear();
        break;
    }
  }
}
