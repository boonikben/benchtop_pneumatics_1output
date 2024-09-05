//Valve Test

//Goal: Only close 1st valve; then only close 2nd valve, then close both valves. Repeat


//Valve pins
const int trans_pin1 = 5;
const int trans_pin2 = 3;

const int delay_time = 1000;



void setup() {
  // put your setup code here, to run once:
  pinMode(trans_pin1, OUTPUT);
  pinMode(trans_pin2, OUTPUT);
  digitalWrite(trans_pin1,LOW);
  digitalWrite(trans_pin2,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trans_pin1,HIGH);
  delay(delay_time);
  //digitalWrite(trans_pin1,LOW);
  //delay(delay_time);
  //digitalWrite(trans_pin2,HIGH);
  //delay(delay_time);
  //digitalWrite(trans_pin2,LOW);
  //delay(delay_time);
  //digitalWrite(trans_pin1,HIGH);
  //digitalWrite(trans_pin2,HIGH);
  //delay(delay_time);
  //digitalWrite(trans_pin1,LOW);
  //digitalWrite(trans_pin2,LOW);
  
  
}
