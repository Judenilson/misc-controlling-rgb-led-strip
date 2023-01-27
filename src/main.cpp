#include <Arduino.h>
#include <FastLED.h>
#include <EEPROM.h>

#define ledPin 5           // Porta Digital Saída para LEDS
#define quantidadeLeds 101 // Quantidade de LEDS na fita
// Consumo da fita WS2812 com 60 LEDs por metro = 2.3A

#define button 7

int8_t effect = 0;
int8_t lastEffect = 0;
int8_t maxEffects = 9;
int addr = 0; // endereço da memória para salvar o efeito
int statusOnOff = 0;

CRGB leds[quantidadeLeds];

void apagarLeds();

void setup()
{
  FastLED.addLeds<WS2812, ledPin, GRB>(leds, quantidadeLeds);
  pinMode(button, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  delay(1000);
  Serial.println("Iniciando Comunicação Serial!");

  effect = EEPROM.read(addr);
  delay(100);
  apagarLeds();
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
  apagarLeds();
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
  apagarLeds();
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
  apagarLeds();
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
  apagarLeds();
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

void effectLoopE()
{
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
}

void effectLoopF()
{
  apagarLeds();
  for (int i = 0; i < quantidadeLeds; i++)
  {
    leds[i] = CRGB(250, 7, 40);
  }
  FastLED.show();
}

void effectLoopG()
{
  apagarLeds();
  for (int i = 0; i < quantidadeLeds; i++)
  {
    leds[i] = CRGB(105, 7, 250);
  }
  FastLED.show();
}

void effectLoopH()
{
  apagarLeds();
  for (int i = 0; i < quantidadeLeds; i++)
  {
    leds[i] = CRGB(0, 255, 0);
  }
  FastLED.show();
}

void effectLoopDefault()
{
  apagarLeds();
  for (int i = 0; i < 11; i++)
  {
    leds[i] = CRGB(255, 255, 255);
  }
  FastLED.show();
}

void effectLoopSetupSave()
{
  apagarLeds();
  for (int i = 0; i < quantidadeLeds; i++)
  {
    leds[i] = CRGB(255, 0, 0);
  }
  FastLED.show();
  delay(250);
  apagarLeds();
  delay(250);
  for (int i = 0; i < quantidadeLeds; i++)
  {
    leds[i] = CRGB(255, 0, 0);
  }
  FastLED.show();
  delay(250);
  apagarLeds();
  delay(250);
  for (int i = 0; i < quantidadeLeds; i++)
  {
    leds[i] = CRGB(255, 0, 0);
  }
  FastLED.show();
  delay(250);
  apagarLeds();
  delay(250);
}

void effectsChange(int effectnumber)
{
  switch (effectnumber)
  {
  case 1:
    effectLoopDefault();
    break;

  case 2:
    effectLoopA();
    break;

  case 3:
    effectLoopB();
    break;

  case 4:
    effectLoopC();
    break;

  case 5:
    effectLoopD();
    break;

  case 6:
    effectLoopE();
    break;

  case 7:
    effectLoopF();
    break;

  case 8:
    effectLoopG();
    break;

  case 9:
    effectLoopH();
    break;

  default:
    effectLoopDefault();
    break;
  }
}

void loop()
{
  if (digitalRead(button))
  {
    int startPress = millis();
    int timerPress = 0;
    while (digitalRead(button))
    {
      timerPress = millis() - startPress;
    }

    if ((timerPress > 700) && (timerPress < 3000)) // ligar e desligar os leds.
    {
      if (statusOnOff)
      {
        apagarLeds();
        statusOnOff = 0;
        Serial.println("Desligando...");
      }
      else
      {
        statusOnOff = 1;
      }
    }

    if (statusOnOff)
    {
      if (timerPress > 3000) // salvar efeito
      {
        EEPROM.update(addr, effect);
        delay(10);
        effectLoopSetupSave();
        Serial.println("Salvando na memória...");
      }
      else if (timerPress > 700) // ativar efeito ao ligar
      {
        effect = EEPROM.read(addr);
        delay(100);
        effectsChange(effect);
        Serial.println("Ligando LEDs...");
      }
      else if (timerPress > 50) // trocar effeito
      {
        effect++;
        if (effect > maxEffects) // mantendo o loop de efeitos
        {
          effect = 1;
          Serial.println("Retornando Loop de efeitos...");
        }
        while (digitalRead(button))
        {
          ;
        }
        if (lastEffect != effect) // só chama os efeitos se houver mudança.
        {
          lastEffect = effect;
          effectsChange(effect);
          Serial.println("Trocando Efeito...");
        }
      }
    }

    Serial.println("Log:");
    Serial.println("Tempo do pressionamento do botão: " + (String)timerPress);
    Serial.println("Status dispositivo: " + (String)statusOnOff);
    Serial.println("Efeito atual: " + (String)effect);
    Serial.println("----------------------------------------");
  }
}