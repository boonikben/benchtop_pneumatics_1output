//Functions

void PosPmpOn(pump_lvl) {

}

void NegPmpOn(pump_lvl) {

}

void PosValveOn(pump_lvl) {

}

void NegValveOn(pump_lvl) {
  

}

float pressureRead(int p_max, int p_min,int sup_voltage){
  float analog_output = analogRead(analog_pin);
  float voltage_output = analog_output *5 / 1023;
  float current_pressure = ((p_max-p_min)*(voltage_output-(0.1*sup_voltage)))/(0.8*sup_voltage);
  return current_pressure;
}
