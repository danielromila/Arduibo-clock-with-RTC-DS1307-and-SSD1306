#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Time.h>
#include <DS1307RTC.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);



void setup()
{
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  
  }

  void loop()
  {
    display.clearDisplay();
    tmElements_t tm;
    if(RTC.read(tm)){
      display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,4);
    print2digits(tm.Hour);
    display.write(':');
    print2digits(tm.Minute);
    display.write(':');
    print2digits(tm.Second);
    display.setCursor(0,25);
    display.setTextSize(1);
    display.print(tm.Day);
    display.write('/');
    display.print(tm.Month);
    display.write('/');
    display.print(tmYearToCalendar(tm.Year));
    display.display();
    
    }
    else
    {
      if(RTC.chipPresent())
      {
        display.setTextSize(1);
  display.setTextColor(WHITE);
        display.print("DS1307 stopped,run set time");
        display.display();
        }
        else
        {
          display.setTextSize(1);
  display.setTextColor(WHITE);
        display.print("DS1307 read error,check circuit");
        display.display();
          }
          delay(9000);
      }
      delay(1000);
     
  }

    void print2digits(int number) {
  if (number >= 0 && number < 10) {
    display.write('0');
  }
  display.print(number);

}
