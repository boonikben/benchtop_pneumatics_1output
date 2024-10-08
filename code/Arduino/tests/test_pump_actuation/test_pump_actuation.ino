/*
  test_pump_actuation
  part of pneumatic control code used in the Hatton lab to pneumatically actuate devices

  Turns pneumatic pump(s) on for [delay_time], then off for [delay_time], repeatedly.
  Alternates between positive reservoir pump, negative reservoir pump, and both.

  NOTE: Assemble circuit first, CHANGE PINS to match circuit (with directions of pumps opposite), THEN run code.

  CAUTION: this code runs pumps without sensory feedback and does not check pressure values
  Do NOT leave running for very long and do NOT run if reservoirs have been highly pressurized
  (although this is unlikely)

  written 2023-11-03 by Katie Allison
  original pneumatics code by Kurtis Laqua and Aly Hassan
*/

const int delay_time = 1000;
int pump_dutycycle = 190; // from 0 (fully OFF) to 255 (fully ON) (should be in the lower half if running nonstop)

const int pump_pins[4]= {10,11,6,9};
const int positivepump_pin1= 10;
const int positivepump_pin2= 11;
const int negativepump_pin1= 6;
const int negativepump_pin2= 9;

void setup() {
  // initialize outputs
  pinMode(positivepump_pin1, OUTPUT);
  pinMode(positivepump_pin2, OUTPUT);
  pinMode(negativepump_pin1, OUTPUT);
  pinMode(negativepump_pin2, OUTPUT);

  // set pin 2 for each pump to be LOW always (since we are not changing direction)
  digitalWrite(positivepump_pin2, LOW);
  digitalWrite(negativepump_pin2, LOW);
}

void loop() {
  // for each pump, turn it on briefly then off briefly.
  // To turn on, write PWM signal at specified duty cycle.
  // To turn off, write logic low.

  // test run of positive pump
  digitalWrite(positivepump_pin1, pump_dutycycle);
  delay(delay_time);
  digitalWrite(positivepump_pin1, 0);
  delay(delay_time);   
       
  // test run of negative pump
  digitalWrite(negativepump_pin1, pump_dutycycle);
  delay(delay_time);
  digitalWrite(negativepump_pin1, 0);
  delay(delay_time);      
  
  // test run of both pumps together
  //digitalWrite(positivepump_pin1, pump_dutycycle);
  //digitalWrite(negativepump_pin1, pump_dutycycle);
  //delay(delay_time);
  //digitalWrite(positivepump_pin1, 0);
  //digitalWrite(negativepump_pin1, 0);
  //delay(delay_time);                     
}
