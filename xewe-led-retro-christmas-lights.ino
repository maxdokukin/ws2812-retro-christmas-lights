#include <FastLED.h>

#define NUM_LEDS 120
#define DATA_PIN 3
#define FLICKR_SPEED 3

CRGB leds[NUM_LEDS];
CRGB colors_map[5] = {
  CRGB(184,   4,   0),   // C9 red    0xB80400
  CRGB(144,  44,   2),   // C9 orange 0x902C02
  CRGB(  4,  96,   2),   // C9 green  0x046002
  CRGB(  7,   7,  88),   // C9 blue   0x070758
  CRGB( 86, 94,  22)    // C9 white  0x606820
};

uint16_t gZ = 0;                    // time axis for noise
uint16_t noiseOffset[NUM_LEDS];     // per-LED noise channels

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(255);
  FastLED.clear();
  FastLED.show();

  // init per-LED noise offsets
  for (int i = 0; i < NUM_LEDS; i++) {
    noiseOffset[i] = random16();    // unique seed per LED
  }
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    // base color pattern
    leds[i] = colors_map[i % 5];

    // independent Perlin noise over time per LED
    uint8_t noise = inoise8(noiseOffset[i], gZ);  // 0..255

    // 255 = full brightness, lower = dimmer
    leds[i].nscale8_video(noise);
  }

  FastLED.show();

  gZ += FLICKR_SPEED;                  // flicker speed (smaller = slower)
  FastLED.delay(1000 / 60); // ~60 FPS
}
