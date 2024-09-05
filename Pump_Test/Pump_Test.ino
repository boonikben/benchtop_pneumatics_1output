// Pump Test Code

// Goal: Open only Valve 1, pump 1. Then delay. Then only valve 2 pump 2. Then close both. Repeat

const int pump_dutycycle = 200; //Level of pumping
const int delay_time = 5000; //(delay in ms)

//H-Bridge Pump Pins (PWM)

const int posPump_pin1 = 11;
const int posPump_pin2 = 10;
const int negPump_pin1 = 9;
const int negPump_pin2 = 6;


//Valve pins
const int trans_pin1 = 5;
const int trans_pin2 = 3;


void setup() {
  // put your setup code here, to run once:


  pinMode(trans_pin1, OUTPUT);
  pinMode(trans_pin2, OUTPUT);

  
  pinMode(posPump_pin1, OUTPUT);
  pinMode(posPump_pin2, OUTPUT);
  pinMode(negPump_pin1, OUTPUT);
  pinMode(negPump_pin2, OUTPUT);

  //Ensure direction doesn't change (both second pins should be LOW at all times)
  digitalWrite(posPump_pin2,LOW);
  digitalWrite(negPump_pin2,LOW);

  //Start with both valves closed
  digitalWrite(trans_pin1,HIGH);
  digitalWrite(trans_pin2,HIGH);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(posPump_pin1,pump_dutycycle);
  digitalWrite(trans_pin1,LOW);
  delay(delay_time);
  
  digitalWrite(posPump_pin1,0);
  digitalWrite(trans_pin1,HIGH);
  delay(delay_time);
  
  digitalWrite(negPump_pin1,pump_dutycycle);
  digitalWrite(trans_pin2,LOW);
  delay(delay_time);
  
  digitalWrite(trans_pin2,HIGH);
  digitalWrite(negPump_pin1,0);
  delay(delay_time);
  

  
  
  

  

}
