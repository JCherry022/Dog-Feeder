//John Cherry
//Dog-Feeder

#include <TimeAlarms.h>
#include <Time.h>
#include <Servo.h>

#define BUTTON A1
Servo s1;
int button=0;
int test=5;


void loop(){
 Alarm.delay(1000); // wait one second between clock display
}

void setup(){    //main method
  s1.attach(A0); //analog pin 0
  s1.write(0); //set servo to position 0
  setTime(7,30,00,1,12,13); //Set to approximate time, try to get it within a few minutes
  Serial.begin(9600); //Set to approximate time, try to get it within a few minutes
  Alarm.alarmRepeat(7,30,01, Dispense);  // 7:30am (and 1 second) every day
  Alarm.alarmRepeat(7,30,11, Dispense);  // 7:30am (and 11 second) every day for testing purposes
  pinMode(9, OUTPUT);
}

void Dispense() {    //method for delays and timers on how the servo spins, waits, and returns to position.
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(100);
  s1.write(170);
  Alarm.delay(2000);
  s1.write(1);
  Alarm.delay(1500);
}