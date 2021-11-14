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
