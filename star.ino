//https://forum.arduino.cc/t/random-color-changing-with-ws2812b-could-the-code-be-any-better/682209

#include <FastLED.h>                     // needed for WS2812 LEDs
#define LED_PIN     4                    // where it's connected to
#define NUM_LEDS    63                    // how many LEDs total
#define BRIGHTNESS  5                  // not too bright, not too dim
#define LED_TYPE    WS2811               // change if needed
#define COLOR_ORDER GRB                  // change if needed
CRGB leds[NUM_LEDS];
byte b[24] = {};

void setup() {
  randomSeed(analogRead(0));
  delay( 300 );                            // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  for (int i = 0; i < 24; i++) {
    b[i] = 0;
  }
}

void loop()
{
  int i = random(NUM_LEDS);
  byte j = random(3);
  leds[i].raw[j] ^= 255;
  FastLED.show();
  delay(25);
}
