#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>
#include <time.h>
#include <ISAButtons.h>
#include <ISA7SegmentDisplay.h>
#include <ISALedControl.h>
#include <ISAOLED.h>

#define LOWER 1
#define HIGHER 2
#define LEFT 3
#define RIGHT 4
#define FORWARD 5
#define BACKWARD 6

ISALiquidCrystal lcd;
ISAButtons buttons;
 
void setup(){
	//LCD
	lcd.begin();
  buttons.init();  
  
   pinMode(KEY_DOWN, INPUT);
   pinMode(KEY_UP, INPUT);  
}

void loop(){

 if(digitalRead(KEY_UP) != true)
 {
  sendMessage(HIGHER);
 }
 if(digitalRead(KEY_DOWN) != true)
 {
  sendMessage(LOWER);
 }

  int joy[2];
  joy[0] = analogRead(JOY1X);
  joy[1] = analogRead(JOY1Y);
  if (joy[0] > 650)
  {
    sendMessage(LEFT);
  }
  else if (joy[0] < 350)
  {
    sendMessage(RIGHT);
  }
  
  if (joy[1] > 650)
  {
    sendMessage(FORWARD);
  }
  else if (joy[1] < 350)
  {
    sendMessage(BACKWARD);
  }
}



void sendMessage (int decision)
{
  lcd.clear();
  lcd.print(decision);
  delay(10);
  //WE NEED TO PUT WI FI SENDING THERE.
  //sprintf(printData, "JOY1X-%04dY-%04d",joy1[0],joy1[1]);
}


