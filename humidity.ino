#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
char HUMI_Sensor = A0;
int Sensor_val;
byte dht11_dat[5];
byte dht11_in;
byte i;

byte read_dht11_dat()
{
  byte i = 0;
  byte result = 0;
  for(i=0 ;i<8 ;i++){
    while(!digitalRead(HUMI_Sensor));
    delayMicroseconds(30);
    if (digitalRead(HUMI_Sensor)!=0)
    bitSet(result, 7- i);
    while(digitalRead(HUMI_Sensor));
  }
  return result;
}

void setup()
{
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("HUMIDITY");
  lcd.setCursor(0, 1);
  lcd.print("TEMP:  HUMI:");
  pinMode(HUMI_Sensor, OUTPUT);
  digitalWrite(HUMI_Sensor, HIGH);
}

void loop()
{
  digitalWrite(HUMI_Sensor, LOW);
  delay(18);
  digitalWrite(HUMI_Sensor, HIGH);
  delayMicroseconds(5);
  pinMode(HUMI_Sensor, INPUT);
  delayMicroseconds(200);
  for( i = 0 ; i<5 ; i++ ){
    dht11_dat[i] = read_dht11_dat[0]+dht11_dat[2];
    lcd.setCursor(5, 1);
    lcd.print(dht11_dat[0], DEC);
    lcd.print('%');
    lcd.setCursor(13, 1);
    lcd.print(dht11_dat[2], DEC);
    lcd.print('C');
    delay(200);
    
  }
}

