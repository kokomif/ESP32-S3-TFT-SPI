#include <Arduino.h>
#include <Arduino_GFX_Library.h>
#define GFX_BL DF_GFX_BL // default backlight pin, you may replace DF_GFX_BL to actual backlight pin
#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */

/* More data bus class: https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class */
Arduino_DataBus *bus = create_default_Arduino_DataBus();

/* More display class: https://github.com/moononournation/Arduino_GFX/wiki/Display-Class */
Arduino_GFX *gfx = new Arduino_ILI9341(bus, DF_GFX_RST, 0 /* rotation */, false /* IPS */);

#endif /* !defined(DISPLAY_DEV_KIT) */

void intro()
{
  
  gfx->setRotation(3);
  gfx->fillScreen(BLACK);
  gfx->setCursor(10, 10);
  gfx->setTextColor(RED);
  gfx->setTextSize(3, 3, 1); // x scale, y scale, pixel margin
  gfx->println("SISTEM");
  gfx->setCursor(10, 40);
  gfx->println("MONITORING");
  gfx->setCursor(10, 70);
  gfx->println("UDARA");
  gfx->setCursor(230, 220);
  gfx->setTextSize(2, 2, 1);
  gfx->setTextColor(BLUE);
  gfx->println("V.3.0.0");
  delay(1000); // 10 seconds
  gfx->fillScreen(BLACK);
}

void indikator() {
  gfx->setCursor(70, 10);
  gfx->setTextColor(RED);
  gfx->setTextSize(3, 3, 1); // x scale, y scale, pixel margin
  gfx->println("INDIKATOR");
  gfx->setCursor(10, 40);
  gfx->println("TEMP  : ");
  gfx->setCursor(10, 70);
  gfx->println("RH    : ");
  gfx->setCursor(10, 100);
  gfx->println("PM 1.0: ");
  gfx->setCursor(10, 130);
  gfx->println("PM 2.5: ");
  gfx->setCursor(10, 160);
  gfx->println("PM  10: ");
}

void value(){
  //Refresh
  gfx->fillRect(140, 40, 250, 250, BLACK);
  //Temperature
  float temp = random(40);
  gfx->setCursor(140, 40);
  gfx->println(temp);
  gfx->setCursor(230, 40);
  gfx->println("C");

  //RH
  int RH = random(99);
  gfx->setCursor(140, 70);
  gfx->println(RH);
  gfx->setCursor(180, 70);
  gfx->println("%");

  //PM 1.0
  int PM1 = random(99);
  gfx->setCursor(140, 100);
  gfx->println(PM1);
  gfx->setCursor(180, 100);
  gfx->println("ug/m3");

  //PM 2.5
  int PM25 = random(99);
  gfx->setCursor(140, 130);
  gfx->println(PM25);
  gfx->setCursor(180, 130);
  gfx->println("ug/m3");

  //PM 10
  int PM10 = random(99);
  gfx->setCursor(140, 160);
  gfx->println(PM10);
  gfx->setCursor(180, 160);
  gfx->println("ug/m3");
}

void setup(void)
{
  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  // while(!Serial);
  Serial.println("Arduino_GFX Hello World example");

#ifdef GFX_EXTRA_PRE_INIT
  GFX_EXTRA_PRE_INIT();
#endif

  // Init Display
  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(BLACK);

#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif
intro();
}

void loop()
{
  indikator();
  value();
  delay(1000);

}
