//Final Code

//Goal: Read pressure from container, open pos/neg valve depending on pressure and start pos/neg pump to increase/ decrease pressure of container

const int pump_dutycycle = 20; //Level of pumping
const int delay_time = 50; //(delay in ms)
const int sup_voltage = 5; //5 volt from H bridge
const int p_min = -100; //-100 off of atm
const int p_max = 100; //in kpa (conversion from 100PSI) // in atm: 6.8046
const int p_goal = 100; //in kpa 
const int p_buffer = 2;
float analog_output;
float voltage_output;
float current_pressure = 0.0;

//defining pins 

//sensor pin
const int analog_pin = A5;

//Valve pins
const int trans_pin1 = 5;
const int trans_pin2 = 3;

//H-Bridge Pump Pins (PWM)

const int posPump_pin1 = 11;
const int posPump_pin2 = 10;
const int negPump_pin1 = 9;
const int negPump_pin2 = 6;


// Variable intitializers


void setup() {
  pinMode(trans_pin1, OUTPUT);
  pinMode(trans_pin2, OUTPUT);
  
  pinMode(posPump_pin1, OUTPUT);
  pinMode(posPump_pin2, OUTPUT);
  pinMode(negPump_pin1, OUTPUT);
  pinMode(negPump_pin2, OUTPUT);


  Serial.begin(9600);
  
  //Ensure direction doesn't change (both second pins should be LOW at all times)
  digitalWrite(posPump_pin2,LOW);
  digitalWrite(negPump_pin2,LOW);

  //Start with both valves closed
  digitalWrite(trans_pin1,LOW);
  digitalWrite(trans_pin2,LOW);
  
  
}
void loop() {
  delay(delay_time);
  
  // put your setup code here, to run once:
  analog_output = analogRead(analog_pin);
  voltage_output = analog_output *5 / 1023;
  current_pressure = ((voltage_output-0.5)/0.02)-100;
  Serial.println(current_pressure);
  if (current_pressure < (p_goal-p_buffer)){
    //Stop negative pumping
    digitalWrite(trans_pin2,LOW);
    digitalWrite(negPump_pin1,LOW);
    //Start positive pumping
    digitalWrite(trans_pin1,HIGH);
    digitalWrite(posPump_pin1,pump_dutycycle);

    //Delay 1 second
    delay(delay_time);
    }
    
  if (current_pressure > (p_goal-p_buffer)){
    //Stop positive pumping
    digitalWrite(trans_pin1,LOW);
    digitalWrite(posPump_pin1,LOW);
    //Start negative pumping
    digitalWrite(trans_pin2,HIGH);
    digitalWrite(negPump_pin1,pump_dutycycle);

    //Delay 1 second
    delay(delay_time);

    }
  
}
