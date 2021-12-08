
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
#define COLOR_ORDER RGB
#define NUM_LEDS 150
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
int brightness = 150;
int brightnessSpeed = 10;
int saturation = 255;
int x = 0;
int xSpeed = 1;

CHSV red = CHSV(0, saturation, brightness);
CHSV orange = CHSV(32, saturation, brightness);
CHSV yellow = CHSV(64, saturation, brightness);
CHSV green = CHSV(96, saturation, brightness);
CHSV aqua = CHSV(128, saturation, brightness);
CHSV blue = CHSV(160, saturation, brightness);
CHSV purple = CHSV(192, saturation, brightness);
CHSV pink = CHSV(224, saturation, brightness);

int speedDelay = 10;
int ledPos = 5;
int direction = 1;
int colorPos = 0;
int groupSize = 1;

int h = 0;
int s = 255;
int v = 255;
CHSV color[] = {red, orange, yellow, green, aqua, blue, purple, pink};

//define colors

int delay1 = 30;
int delay2 = 25;
int delay3 = 3000;
int delay4;
int delay5;
int delay6;

void setup()
{
  FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(strips, NUM_LEDS);
  FastLED.setBrightness(brightness);
  //  for (int i = 0; i < NUM_LEDS; i++) {
  //    strips[i] = CRGB::White;
  //    FastLED.delay(1);
  //    strips[i] = CRGB::Black;
  //    FastLED.delay(1);
  //  }

  for (int i = 0; i < NUM_LEDS; i++)
  {
    strips[i] = CRGB::Black;
  }

  FastLED.show();

  // RG
  // delay1 = 7;
  // for (int i = 0; i < NUM_LEDS; i += 2)
  // {

  //   strips[i] = CRGB::Green;

  //   strips[i + 1] = CRGB::Red;
  //   FastLED.delay(delay1);
  // }
  pattern1();
}

void loop()
{

  pattern1();
  pattern2();
  FastLED.delay(5000);
  pattern3();
  FastLED.delay(5000);
  pattern4();
  FastLED.delay(5000);
  pattern5();
  FastLED.delay(5000);
  pattern6();
  FastLED.delay(5000);
  pattern7();
  FastLED.delay(5000);
  pattern8();
  FastLED.delay(5000);
  pattern9();
  FastLED.delay(5000);
  pattern10();
  FastLED.delay(5000);
  for (int i = 0; i < 5000; i++)
  {
    twinkle();
  }

  //for(int i = 0; i < NUM_LEDS; i++){
  //  strips[i] = CHSV(h, s, v);
  //
  //
  //}

  //  pattern 1
  //  for (int i = 0; i < NUM_LEDS; i++) {
  //    strips[i] = CRGB::Green;
  //    FastLED.delay(delay2);
  //  }
  //
  //  for (int i = 0; i < NUM_LEDS; i++) {
  //    strips[i] = CRGB::Black;
  //    FastLED.delay(delay1);
  //  }

  //    int stripEnd = x + 7;
  //   for (int i = x; i < stripEnd ; i++){
  //
  //
  //    strips[20+i] = CRGB::Green;
  //    FastLED.show();
  //  //  strips[20+i] = CRGB::Black;
  //    FastLED.delay(20);
  //
  //
  //    if(x>99){
  //      xSpeed *= -1;
  //    }
  //    x += xSpeed;
  //
  //
  //
  //   }
  //
  //
  //
  FastLED.delay(1);
}

void pattern1()
{

  // red green flash
  int runcount = 20;
  while (runcount > 0)
  {
    delay2 = 500;

    for (int i = 0; i < NUM_LEDS; i += 2)
    {

      strips[i] = CRGB::Green;
      strips[i + 1] = CRGB::Red;
    }

    FastLED.show();
    FastLED.delay(delay2);

    for (int i = 0; i < NUM_LEDS; i += 2)
    {

      strips[i] = CRGB::Red;
      strips[i + 1] = CRGB::Green;
    }

    FastLED.show();
    FastLED.delay(delay2);
    runcount--;
  }
}

void pattern2()
{

  int runcount = 20;
  while (runcount > 0)
  {
    // red green roll

    delay1 = 7;
    delay2 = 10;
    delay3 = 1000;

    for (int i = 0; i < NUM_LEDS; i += 2)
    {

      strips[i] = CRGB::Green;
      FastLED.delay(delay1);
      strips[i + 1] = CRGB::Red;
      FastLED.delay(delay1);
    }

    FastLED.delay(delay3);

    for (int i = 0; i < NUM_LEDS; i += 2)
    {

      strips[i] = CRGB::Red;
      FastLED.delay(delay1);
      strips[i + 1] = CRGB::Green;
      FastLED.delay(delay1);
    }

    FastLED.delay(delay3);
    runcount--;
  }
}

void pattern3()
{
  // instant RG
  for (int i = 0; i < NUM_LEDS; i += 2)
  {

    strips[i] = CRGB::Green;
    strips[i + 1] = CRGB::Red;
  }
}
void pattern4()
{
  // transition center out
  int center = (NUM_LEDS / 2);
  int x = 1;
  for (int i = center; i < NUM_LEDS; i += 1)
  {
    strips[i] = CRGB::Blue;
    strips[center - x] = CRGB::Blue;
    FastLED.delay(500);
    x += 1;
  }
}

void pattern5()
{
  // transition center random color
  int colorIndex = random(8);
  CHSV c = color[colorIndex];
  int center = (NUM_LEDS / 2);
  int x = 1;
  for (int i = center; i < NUM_LEDS; i += 1)
  {
    strips[i] = c;
    strips[center - x] = c;
    FastLED.delay(500);
    x += 1;
  }
}

void pattern6()
{
  //clear strip
  // for (int i = 0; i < NUM_LEDS; i += 1)
  // {
  //   strips[i] = CRGB::Black;
  // }

  // FastLED.delay(1);
  int pos = 0;
  for (int j = 0; j < NUM_LEDS; j += 10)
  {

    for (int i = pos; i < pos + 10; i += 1)
    {
      strips[i] = CRGB::Blue;
      FastLED.delay(50);
    }
    FastLED.delay(1000);
    pos += 10;
  }
}
void pattern7()
{
  // randomize all lights
  for (int i = 0; i < NUM_LEDS; i += 1)
  {
    strips[i] = CHSV(random(255), saturation, brightness);
    FastLED.delay(30);
  }
}
void pattern8()
{
  // randomize one single light
  strips[random(NUM_LEDS)] = CHSV(random(255), saturation, brightness);
  FastLED.delay(50);
}

void pattern9()
{

  for (int i = 0; i < NUM_LEDS; i += 1)
  {
    strips[i] = CHSV(random(255), saturation, brightness);
    FastLED.delay(150);
    // strips[i] = CRGB::Black;
    // FastLED.delay(30);
  }
}

void pattern10()
{

  delay1 = 150;

  for (int i = 0; i < NUM_LEDS; i += 1)
  {
    strips[i] = CHSV(random(255), saturation, brightness);
    FastLED.delay(delay1);
    // strips[i] = CRGB::Black;
    // FastLED.delay(30);
    int route = random(10);
    if (route)
    {
      delay1 -= random(5);
    }
    else
    {
      delay1 += random(25);
    }
    if (delay1 < 1)
    {
      delay1 = 1;
    }
  }
}

void twinkle()
{
  int light = random(NUM_LEDS);
  CRGB backup = strips[light];

  strips[light] = CRGB::White;
  FastLED.delay(50);
  strips[light] = backup;
  FastLED.delay(random(50, 1000));
}

void breathe()
{
  // breath
  FastLED.setBrightness(brightness);
  FastLED.delay(1);
  FastLED.show();
  brightness += brightnessSpeed;
  if (brightness > 255)
  {
    brightness = 254;
    brightnessSpeed *= -1;
  }
  if (brightness < 70)
  {
    brightness = 71;
    brightnessSpeed *= -1;
  }
}
