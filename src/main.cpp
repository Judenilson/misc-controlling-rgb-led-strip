#include <Arduino.h>
#include <FastLED.h>

#define ledPin 5           // Porta Digital Saída para LEDS
#define quantidadeLeds 101 // Quantidade de LEDS na fita
// Consumo da fita WS2812 com 60 LEDs por metro = 2.3A

#define button 7

int effect = 0;
int lastEffect = 0;
int maxEffects = 9;

CRGB leds[quantidadeLeds];

void setup()
{
  FastLED.addLeds<WS2812, ledPin, GRB>(leds, quantidadeLeds);
  pinMode(button, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  delay(1000);
  Serial.println("Iniciando Comunicação Serial!");
}

void apagarLeds()
{
  for (int i = 0; i < quantidadeLeds; i++)
  {
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
}

void effectLoopA()
{
  while (true)
  {
    for (int i = 0; i < quantidadeLeds; i++)
    {
      leds[i] = CRGB(105, 7, 250);
      leds[quantidadeLeds - 1 - i] = CRGB(250, 7, 40);
      FastLED.show();
      delay(10);
      leds[i] = CRGB(0, 0, 0);
      leds[quantidadeLeds - 1 - i] = CRGB(0, 0, 0);
      FastLED.show();

      if (digitalRead(button))
      {
        return;
      }
    }
    for (int i = 0; i < quantidadeLeds; i++)
    {
      leds[i] = CRGB(250, 7, 40);
      leds[quantidadeLeds - 1 - i] = CRGB(105, 7, 250);
      FastLED.show();
      delay(10);
      leds[i] = CRGB(0, 0, 0);
      leds[quantidadeLeds - 1 - i] = CRGB(0, 0, 0);
      FastLED.show();

      if (digitalRead(button))
      {
        return;
      }
    }
  }
}

void effectLoopB()
{
  for (int i = 0; i < quantidadeLeds; i++)
  {
    leds[i] = CRGB(105, 7, 250);
  }
  FastLED.show();
  while (true)
  {
    for (int i = 0; i < quantidadeLeds + 10; i++)
    {
      if (i < quantidadeLeds)
      {
        leds[i] = CRGB(250, 7, 40);
      }
      if (i > 9)
      {
        leds[i - 10] = CRGB(105, 7, 250);
      }
      FastLED.show();
      delay(10);
      if (digitalRead(button))
      {
        return;
      }
    }
    for (int i = quantidadeLeds - 1; i > -10; i--)
    {
      if (i > 0)
      {
        leds[i] = CRGB(250, 7, 40);
      }
      if (i < quantidadeLeds - 10)
      {
        leds[i + 10] = CRGB(105, 7, 250);
      }
      FastLED.show();
      delay(10);
      if (digitalRead(button))
      {
        return;
      }
    }
  }
}

void effectLoopC()
{
  int pause = 50;
  while (true)
  {
    for (int i = 0; i < quantidadeLeds; i++)
    {
      leds[i] = CRGB(105, 7, 250);
      delay(pause);
      FastLED.show();
      if (digitalRead(button))
      {
        return;
      }
    }
    for (int i = 0; i < quantidadeLeds; i++)
    {
      leds[i] = CRGB(250, 7, 40);
      delay(pause);
      FastLED.show();
      if (digitalRead(button))
      {
        return;
      }
    }
    for (int i = quantidadeLeds - 1; i >= 0; i--)
    {
      leds[i] = CRGB(105, 7, 250);
      delay(pause);
      FastLED.show();
      if (digitalRead(button))
      {
        return;
      }
    }
    for (int i = quantidadeLeds - 1; i >= 0; i--)
    {
      leds[i] = CRGB(250, 7, 40);
      delay(pause);
      FastLED.show();
      if (digitalRead(button))
      {
        return;
      }
    }
  }
}

void effectLoopD()
{
  int pause = 50;

  for (int i = 0; i < quantidadeLeds; i++)
  {
    leds[i] = CRGB(105, 7, 250);
  }
  FastLED.show();

  while (true)
  {
    for (int i = 50; i < quantidadeLeds; i++)
    {
      leds[i] = CRGB(250, 7, 40);
      leds[100 - i] = CRGB(250, 7, 40);
      delay(pause);
      FastLED.show();
      if (digitalRead(button))
      {
        return;
      }
    }
    for (int i = 50; i < quantidadeLeds; i++)
    {
      leds[i] = CRGB(105, 7, 250);
      leds[100 - i] = CRGB(105, 7, 250);
      delay(pause);
      FastLED.show();
      if (digitalRead(button))
      {
        return;
      }
    }
  }
}

void loop()
{
  if (digitalRead(button))
  {
    effect++;

    delay(100);
    while (digitalRead(button))
    {
      ;
    }
  }
  if (effect > maxEffects)
  {
    effect = 1;
  }

  if (lastEffect != effect)
  {
    lastEffect = effect;

    switch (effect)
    {
    case 1:
      apagarLeds();
      for (int i = 0; i < quantidadeLeds; i++)
      {
        if (i >= 75)
        {
          leds[i] = CRGB(250, 7, 40);
        }
        else if (i >= 50)
        {
          leds[i] = CRGB(105, 7, 250);
        }
        else if (i >= 25)
        {
          leds[i] = CRGB(250, 7, 40);
        }
        else
        {
          leds[i] = CRGB(105, 7, 250);
        }
      }
      FastLED.show();
      break;

    case 2:
      apagarLeds();
      effectLoopA();
      break;

    case 3:
      apagarLeds();
      effectLoopB();
      break;

    case 4:
      apagarLeds();
      for (int i = 0; i < quantidadeLeds; i++)
      {
        leds[i] = CRGB(250, 7, 40);
      }
      FastLED.show();
      break;

    case 5:
      apagarLeds();
      for (int i = 0; i < quantidadeLeds; i++)
      {
        leds[i] = CRGB(105, 7, 250);
      }
      FastLED.show();
      break;

    case 6:
      apagarLeds();
      for (int i = 0; i < quantidadeLeds; i++)
      {
        leds[i] = CRGB(0, 255, 0);
      }
      FastLED.show();
      break;

    case 7:
      apagarLeds();
      effectLoopC();
      break;

    case 8:
      apagarLeds();
      effectLoopD();
      break;

    default:
      apagarLeds();
      break;
    }
  }
}
