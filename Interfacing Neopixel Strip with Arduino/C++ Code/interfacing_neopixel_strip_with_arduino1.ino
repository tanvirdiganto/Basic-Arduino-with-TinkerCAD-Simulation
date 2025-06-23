// This code is for the Arduino project shown in the video, simulating a
// NeoPixel strip controlled by an Arduino UNO in Tinkercad.

// Step 1: Include the Adafruit NeoPixel library
// This library provides functions to easily control addressable RGB LEDs.
#include <Adafruit_NeoPixel.h>

// Step 2: Define constants for the NeoPixel strip
#define PIN        6  // The Arduino digital pin connected to the NeoPixel's Data In (DIN)
#define N_LEDS     4  // The number of LEDs on the strip

// Step 3: Create an instance of the Adafruit_NeoPixel class
// Parameters:
// 1. Number of LEDs in the strip (N_LEDS)
// 2. Arduino pin number (PIN)
// 3. Pixel type flags. NEO_GRB means the color order is Green, Red, Blue.
//    NEO_KHZ800 means the data is sent at 800 KHz (most common for NeoPixels).
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// Step 4: setup() function - runs once when the Arduino starts
void setup() {
  // Initialize the NeoPixel library. This must be called before any other
  // strip functions are called.
  strip.begin();
  
  // Update the strip to ensure all pixels are 'off' initially.
  strip.show(); 
}

// Step 5: loop() function - runs repeatedly after setup()
void loop() {
  // Call the 'chase' function for different colors in a sequence.
  
  // Chase with Red color
  chase(strip.Color(255, 0, 0)); // strip.Color() creates a color from R, G, B values.
  
  // Chase with Green color
  chase(strip.Color(0, 255, 0));
  
  // Chase with Blue color
  chase(strip.Color(0, 0, 255));
}

// Step 6: Custom 'chase' function
// This function creates a "color wipe" effect. It fills the strip with
// a specific color, one pixel at a time.
void chase(uint32_t color) {
  // Loop through each pixel on the strip
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    // Set the color of the current pixel.
    strip.setPixelColor(i, color);
    
    // Send the updated pixel color to the strip.
    strip.show();
    
    // Pause for a short duration to make the effect visible.
    delay(25);
  }
}
