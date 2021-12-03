#include <bitswap.h>
#include <chipsets.h>
#include <color.h>
#include <colorpalettes.h>
#include <colorutils.h>
#include <controller.h>
#include <cpp_compat.h>
#include <dmx.h>
#include <FastLED.h>
#include <fastled_config.h>
#include <fastled_delay.h>
#include <fastled_progmem.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <fastspi_types.h>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <lib8tion.h>
#include <noise.h>
#include <pixelset.h>
#include <pixeltypes.h>
#include <platforms.h>
#include <power_mgt.h>

//#include <FastLED.h>

// How many leds in your strip?

#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 100
#define DATA_PIN 4
//#define NUM_STRIPS 1
//For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN

//#define CLOCK_PIN 13

// Define the array of leds
//CRGB strip1[NUM_LEDS];
//CRGB strip2[NUM_LEDS];
//CRGB strip3[NUM_LEDS];
//CRGB strip4[NUM_LEDS];
//CRGB strip5[NUM_LEDS];
//CRGB strip6[NUM_LEDS];
//CRGB strip7[NUM_LEDS];
CRGB strips[NUM_LEDS];
int brightness = 60;
int saturation = 255;
int x = 0;
int xSpeed = 1;
int pattern = 1;

CHSV red = CHSV(0, saturation, brightness);
CHSV orange = CHSV(32, saturation, brightness);
CHSV yellow = CHSV(64, saturation, brightness);
CHSV green = CHSV(96, saturation, brightness);
CHSV aqua = CHSV(128, saturation, brightness);
CHSV blue = CHSV(160, saturation, brightness);
CHSV purple = CHSV(192, saturation, brightness);
CHSV pink = CHSV(224, saturation, brightness);

int speedDelay = 10;
int ledPos = 0;
int direction = 1;
int colorPos = 0;
int groupSize = 1;

int h = 0;
int s = 255;
int v = 255;
CHSV color[] = {red, orange, yellow, green, aqua, blue, purple, pink};

//define colors

void setup()
{
  // Uncomment/edit one of the following lines for your leds arrangement.
  // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(strips, NUM_LEDS);
  // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  //  FastLED.addLeds<NEOPIXEL, 1>(strips[6], NUM_LEDS);
  //  FastLED.addLeds<LED_TYPE, 2>(strips, NUM_LEDS);
  //  FastLED.addLeds<NEOPIXEL, 3>(strips[4], NUM_LEDS);
  //  FastLED.addLeds<NEOPIXEL, 4>(strips[3], NUM_LEDS);
  //  FastLED.addLeds<NEOPIXEL, 5>(strips[2], NUM_LEDS);
  //  FastLED.addLeds<NEOPIXEL, 6>(strips[1], NUM_LEDS);
  //  FastLED.addLeds<NEOPIXEL, 7>(strips[0], NUM_LEDS);
  // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);

  // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<P9813, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<APA102, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<DOTSTAR, RGB>(leds, NUM_LEDS);

  // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);

  // black out strib before doing anything to clear previouse program
  for (int i = 0; i < NUM_LEDS; i++)
  {
    strips[i] = CRGB::Black;
  }
  FastLED.show();
  FastLED.delay(1000);
}

void loop()
{

  if (pattern == 1)
  {

    // turn all lights to current set color
    for (int i = 0; i < NUM_LEDS; i++)
    {
      strips[i] = CHSV(h, s, v);
    }

    // show changes
    FastLED.show();

    //update hue value
    h = h + 1;
    if (h >= 255)
    {
      h = 0;
    }

    FastLED.delay(100);
  }
  else if (pattern == 2)
  {

    // turn all lights to current set color
    for (int i = ledPos; i < 5; i++)
    {
      strips[i] = CHSV(h, s, v);
    }

    // show changes
    FastLED.show();

    FastLED.delay(100);
  }
}

// for (int i = 0; i < 7 ; i++){
//
//
//  strips[20+i] = CHSV(224, saturation, (brightness - i));
//  FastLED.show();
////  strips[20+i] = CRGB::Black;
//  delay(30);
//
//
//  if(x>99){
//    xSpeed *= -1;
//  }
//  x += xSpeed;
//
//
//
// }
