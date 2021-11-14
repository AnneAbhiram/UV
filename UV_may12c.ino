#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
void setup()
{
  Serial.begin(9600);
  lcd.init(); // initialize the lcd
  lcd.backlight(); // turning on the backlight on the arduino
}

void loop()
{
  float sensorVoltage;
  float sensorValue;

  sensorValue = analogRead(A0); // raw input from sensor
  sensorVoltage = sensorValue / 1024 * 5.0; // calculating the UV intensity
  Serial.print("sensor reading = ");
  Serial.print(sensorValue);
  Serial.print('\n');

  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage);
  Serial.println(" V");
  Serial.print('\n');

  lcd.setCursor(0, 0); // to print on the first line
  lcd.print("UV : ");
  lcd.print(sensorVoltage);
  lcd.setCursor(0, 1); // to print on the second line
  lcd.print("Protection?");
  if (sensorVoltage < 0.318) // condition start
  {
    lcd.print(" no"); // if value is less than .3 then it is safe i.e. no protection needed
  }
  else
  {
    lcd.print(" yes"); // if sensor value above .3 then sunscreen or other protection needed
  }
  delay(3000);
}





/*
   Hello my name is Abhiram i am from ECE 2nd year. My project is a UV intensity detector for skin protection.
   It gives suggestions based on the output value. Now i will show you the working! I will plugin the arduino nano. Run the code.
   The way it works is it gives the output based on the presence of UV light. The arduino determines the UV intensity based on the input voltage from the sensor.
   Now the value is so that means it is safe. Now let us put a led light near the sensor...
   so yes there is not much change in the value it is obvious because there is not uv content in the light. I will attach a picture when sunliht falls on this sensor.

*/
