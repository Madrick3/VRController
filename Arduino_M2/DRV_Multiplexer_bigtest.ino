/**
 * 
 * Names: Noah Martin & Patrick Flaherty 
 * Date: 02/24/2020
 * Reason of this Portion: Program to use Multiplexer & DRV Drivers
 * Sets up the 
 * 
 */
#include <TimerOne.h>
#include <Wire.h>
#include "Adafruit_DRV2605.h"

//Define Multiplexer Selector
#define TCAADDR 0x70

//Define the varying DRV2605 Mux Outputs
#define RTMUX 0
#define RIMUX 1
#define RMMUX 2
#define LTMUX 3
#define LIMUX 4
#define LMMUX 5

/* Assign a Unique ID to each Controller */
Adafruit_DRV2605 R_T;
Adafruit_DRV2605 R_I;
Adafruit_DRV2605 R_M;
Adafruit_DRV2605 L_T;
Adafruit_DRV2605 L_I;
Adafruit_DRV2605 L_M;

void tcaselect(uint8_t i)
{
  if (i > 7) 
  {
    return;
  }
  
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}
 
/*Setup Multiplexer Guy*/
void setup(void) 
{
  Serial.begin(115200);
  //Serial.println("DRV2605L Testie Tester Guy"); Serial.println("");

  R_T.begin();
  R_I.begin();
  R_M.begin();
  L_T.begin();
  L_I.begin();
  L_M.begin();

//Select the Library
  R_T.selectLibrary(1);
  R_I.selectLibrary(1);
  R_M.selectLibrary(1);
  L_T.selectLibrary(1);
  L_I.selectLibrary(1);
  L_M.selectLibrary(1);

//Select the Internal Trigger
  R_T.setMode(DRV2605_MODE_INTTRIG);
  R_I.setMode(DRV2605_MODE_INTTRIG);
  R_M.setMode(DRV2605_MODE_INTTRIG);
  L_T.setMode(DRV2605_MODE_INTTRIG);
  L_I.setMode(DRV2605_MODE_INTTRIG);
  L_M.setMode(DRV2605_MODE_INTTRIG);

  
  /* Initialize the 1st DRV Driver */
  tcaselect(RTMUX);
  if(!R_T.begin())
  {
    /* There was a problem detecting the DRV2605 ... check your connections */
    Serial.println("Ooops, no DRV2605 on Right Thumb detected ... Check your wiring!");
    while(1);
  }
  /* Initialise the 2nd DRV DRIVER */
  tcaselect(RIMUX);
  if(!R_I.begin())
  {
    /* There was a problem detecting the DRV2605 ... check your connections */
    Serial.println("Ooops, no DRV2605 on Right Index detected ... Check your wiring!");
    while(1);
  }

    /* Initialize the 3rd DRV DRIVER */
  tcaselect(RMMUX);
  if(!R_M.begin())
  {
    /* There was a problem detecting the DRV2605 ... check your connections */
    Serial.println("Ooops, no DRV2605 on Right Middle  detected ... Check your wiring!");
    while(1);
  }
  /* Initialise the 4th DRV Driver */
  tcaselect(LTMUX);
  if(!L_T.begin())
  {
    /* There was a problem detecting the DRV2605 ... check your connections */
    Serial.println("Ooops, no DRV2605 on Left Thumb  detected ... Check your wiring!");
    while(1);
  }
  /* Initialize the 5th DRV Driver  */
  tcaselect(LIMUX);
  if(!L_I.begin())
  {
    /* There was a problem detecting the DRV2605 ... check your connections */
    Serial.println("Ooops, no DRV2605 on Left Index detected ... Check your wiring!");
    while(1);
  }
  
  /* Initialise the 6th DRV Driver  */
  tcaselect(LMMUX);
  if(!L_M.begin())
  {
    /* There was a problem detecting the DRV2605 ... check your connections */
    Serial.println("Ooops, no DRV2605 on Left Middle detected ... Check your wiring!");
    while(1);
  }
  Serial.println("AREEEEE YOUUUUU READDDYYYYY TOOOOOO RUMMMMBBLLLEEEEEE!?");
/*
//Asks for Timer after interval of time for Interrupt
  Timer1.intialize(10000);
  Timer1.attachInterrupt(callback); 
*/
}





/*
 * 
 * Names: Noah Martin & Patrick Flaherty 
 * Date: 02/24/2020
 * Reason of this Portion: Intialize all of the Vibrations library value
 * Tell what Effect We are on and start the memory allocated waveform
 * Turn off the effect so that we are only providing appropriate feedback
 * 
 */
 
 uint8_t effect = 1;
 
void loop() 
{
  //We are finally in the Fat Old Loop
  Serial.println("We ARE.... not PSU!!!");

  //Create Timer and See Time Elapse
  unsigned long StartTimer = micros();
  
  //Initiate Vibrating on all of the Devices
  Serial.print(effect, DEC);
  Serial.println(" - This is the Next Effect");
  tcaselect(RTMUX);
  R_T.setWaveform(0, effect);
  R_T.setWaveform(1, 0);
  R_T.go();
  Serial.println("We are Running Right Thumb Homie");
 
  Serial.print(effect, DEC);
  Serial.println(" - This is the Next Effect");
  tcaselect(RIMUX);
  R_I.setWaveform(0, effect);
  R_I.setWaveform(1, 0);
  R_I.go();
  Serial.println("We are Running Right Index Homie");
  
  Serial.print(effect, DEC);
  Serial.println(" - This is the Next Effect");
  tcaselect(RMMUX);
  R_M.setWaveform(0, effect);
  R_M.setWaveform(1, 0);
  R_M.go();
  Serial.println("We are Running Right Middle Homie");
  
  Serial.print(effect, DEC);
  Serial.println(" - This is the Next Effect");
  tcaselect(LTMUX);
  L_T.setWaveform(0, effect);
  L_T.setWaveform(1, 0);
  L_T.go();
  Serial.println("We are Running Left Thumb Homie");
  
  Serial.print(effect, DEC);
  Serial.println(" - This is the Next Effect");
  tcaselect(LIMUX);
  L_I.setWaveform(0, effect);
  L_I.setWaveform(1, 0);
  L_I.go();
  Serial.println("We are Running Left Index Homie");
  
  Serial.print(effect, DEC);
  Serial.println(" - This is the Next Effect");
  tcaselect(LMMUX);
  L_M.setWaveform(0, effect);
  L_M.setWaveform(1, 0);
  L_M.go();
  Serial.println("We are Running Left Middle Homie");
  
  delay(1000);

  R_T.stop();
  R_I.stop();
  R_M.stop();
  L_T.stop();
  L_I.stop();
  L_M.stop();

  //Create End Timer to See Time Elapse
  unsigned long EndTimer = micros();
  float Total_Time = ((EndTimer - StartTimer)-1000000)/1000000.000;
  Serial.print("The total time elapse since the motors started = "); 
  Serial.print(Total_Time, DEC);
  Serial.print("\n"); 
  
  effect++;
  if(effect == 123)
  {
    effect = 1;
  }
}
