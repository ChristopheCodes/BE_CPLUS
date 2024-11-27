#include <string.h>
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;
// attribution des PIN
int pin_LED_PIETONS = D7 ;
int pin_BUTTON_PIETONS = D8 ;
int state = LOW ;

class FeuxCirculation{
  private:
    int colorRed ;
    int colorGreen ;
    int colorOrange ;
    int select ;   // if select = 1 => Red, 2 => Orange and 3=> Green
  
  public:
    FeuxCirculation() {
      colorRed = 1;
      colorOrange = 0;
      colorGreen = 0;
    }
    void setSelect(int value){select=value ;}
    void setFeux(int Selec) {
      switch(Selec) {
      case 2:
        colorRed = 0;
        colorOrange = 1;
        colorGreen = 0;
        break ;
      case 1:
        colorRed = 1;
        colorOrange = 0;
        colorGreen = 0;
        break ; 
      case 3:
        colorRed = 0;
        colorOrange = 0;
        colorGreen = 1;
        break ;
      default:
        break ;
      }
    } 
    ~FeuxCirculation(){
    }
} ;


void setup() {
  // put your setup code here, to run once:
  pinMode(pin_LED_PIETONS,OUTPUT);
  pinMode(pin_BUTTON_PIETONS,INPUT) ;
  lcd.begin(16,2) ;
  lcd.setColor(1) ;

}

void loop() {

  lcd.clear() ;
  lcd.setCursor(0,1) ;
  if (digitalRead(pin_BUTTON_PIETONS)==HIGH) {
    state = !state ;
    lcd.setColor(2) ;
  } else {
    lcd.setColor(1) ;
  }
  digitalWrite(pin_LED_PIETONS,state) ;


  delay(100) ;
}
