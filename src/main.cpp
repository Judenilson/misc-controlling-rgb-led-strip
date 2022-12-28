#include <Arduino.h>
#include <FastLED.h>

#define ledPin 5          // Porta Digital Saída para LEDS
#define quantidadeLeds 101 // Quantidade de LEDS na fita
// Consumo da fita WS2812 com 60 LEDs por metro = 2.3A

CRGB leds[quantidadeLeds];

void setup()
{
  FastLED.addLeds<WS2812, ledPin, GRB>(leds, quantidadeLeds);
}

void loop()
{
  for (int i = 0; i < 30; i++)
  {
    leds[i] = CRGB(105, 7, 250);
  }
  FastLED.show();
    for (int i = 30; i < 60; i++)
  {
    leds[i] = CRGB(250, 7, 40);
  }
  FastLED.show();
    for (int i = 60; i < 90; i++)
  {
    leds[i] = CRGB(105, 7, 250);
  }
  FastLED.show();
    for (int i = 90; i < quantidadeLeds; i++)
  {
    leds[i] = CRGB(250, 7, 40);
  }
  FastLED.show();
}
