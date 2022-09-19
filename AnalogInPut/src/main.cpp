/*
* I, Cole Spiers, student number 000389039, 
* certify that this material is my original work. 
* No other person's work has been used without due acknowledgment 
* and I have not made my work available to anyone else.
* 2022-09-19
*/
#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
}

double calcVoltage(int iVal)
{
  double voltage;
  voltage = iVal * 0.0032226563;
  return voltage;
}

double calcTemp(int iVal)
{
  double temp;
  temp = iVal * 0.048828125;
  return temp;
}

String answer(double temp)
{
  String ans;
  if(temp > 35)
  {
    ans = "Too Hot!";
  }
  else if(temp == 30 || temp > 30)
  {
    ans = "Hot";
  }
  else if(temp == 25 || temp > 25)
  {
    ans = "Warm";
  }
  else if(temp == 15 || temp > 15)
  {
    ans = "Perfect";
  }
  else if(temp == 10 || temp > 10)
  {
    ans = "Cool";
  }
  else
  {
    ans = "Cold!";
  }
  return ans;
}
 
void loop() { 
  int iVal;

  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0);
  double temp = calcTemp(iVal);
  String ans = answer(temp);

  // print value to the USB port 
  Serial.println("Digitized output of " + String(iVal) +" is equivalent to a temperature input of " + String(calcTemp(iVal)) + " deg. C, which is " + ans);
 
  // wait 2 seconds (2000 ms) 
  delay(2000); 
}