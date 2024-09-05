//Test Sensor 

//Goal: To read analog voltage values from the sensor corresponding to pressure.
// Should = 1 atm assuming correct function

//sensor pin
const int analog_pin = A5;
float analog_output;
float voltage;
const int sup_voltage = 5; //5 volt from H bridge
const int p_min = 0; //0 pa min
const int p_max = 689.476; //in kpa (conversion from 100PSI)
float current_pressure = 0.0;



void setup() {
  // put your setup code here, to run once:
  //Start Serial
  Serial.begin(9600);
  pinMode(analog_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analog_output = analogRead(analog_pin);
  //Serial.println(analog_output);
  voltage = (analog_output *5 / 1023);
  Serial.println(voltage);
  current_pressure = ((p_max-p_min)*(voltage-(0.1*sup_voltage)))/(0.8*sup_voltage);
  //Serial.println(current_pressure);
  
  delay(5000);


}
