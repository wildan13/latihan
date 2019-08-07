
#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

int buzzer = 13;
int rs1 = 5;    // Rs = Rotary Switch
int rs2 = 6; 
int rs3 = 7;
int rs4 = 8;
int selectrs1=0;
int selectrs2=0;
int selectrs3=0;
int selectrs4=0;

const int lampu = 4;
const int triggerPin = 2;      //Trig pin
const int MAX_DISTANCE= 200;
const int echoPin = 3;//Echo pin
int var;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
NewPing sonar(triggerPin, echoPin, MAX_DISTANCE);

void setup()
{
  lcd.begin (16,2);
  lcd.backlight();
  pinMode(triggerPin,OUTPUT);  // Trigger is an output pin
  pinMode(echoPin,INPUT);      // Echo is an input pin
  Serial.begin(9600);          // Serial Output
  pinMode(lampu,OUTPUT);
  pinMode(buzzer,OUTPUT);
  digitalWrite(lampu,HIGH);
  pinMode(rs1,INPUT);       // rotary switch 1
  pinMode(rs2,INPUT); 
  pinMode(rs3,INPUT);
  pinMode(rs4,INPUT);
}
 
void loop()
{
  unsigned int uS = sonar.ping();
  float jarak=sonar.convert_cm(uS);
  lcd.setBacklight(HIGH);
  selectrs1=digitalRead(rs1);
  selectrs2=digitalRead(rs2);
  selectrs3=digitalRead(rs3);
  selectrs4=digitalRead(rs4);
  if (selectrs1 == HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menu Terapi");
    lcd.setCursor(0,1);
    lcd.print("Pilih Waktu");
    lcd.setCursor(9,1);
    delay(1000);
  }
 else if (selectrs2 == HIGH)
 {  
    Serial.println ("Terapi 10 menit");
    Serial.println ("Jarak :");
    Serial.println (jarak);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Terapi 10 menit");
    lcd.setCursor(0,1);
    lcd.print("Jarak: ");
    lcd.setCursor(6,1);
    lcd.print(jarak);
    lcd.setCursor(14,1);
    lcd.print("cm");
    delay(1000);
  
    if(jarak<40 && jarak>34)
    {  
      for (int i=2 ; i>= 0 ; i--) {
      Serial.println("tunggu");  
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sisa Waktu : ");
      lcd.setCursor(14,0);
      lcd.print(i);
      lcd.setCursor(0,1);
      lcd.print("Jarak: ");
      lcd.setCursor(6,1);
      lcd.print(jarak);
      lcd.setCursor(14,1);
      lcd.print("cm");
      digitalWrite(lampu, LOW);
      delay(60000); 
    }
    digitalWrite(lampu, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    }
    else
    {
      unsigned int uS = sonar.ping();
      float jarak=sonar.convert_cm(uS);
      Serial.println("kurang");
      delay(1000);
    }
  }
  
  else if (selectrs3 == HIGH)
  { 
    Serial.println ("Terapi 15 menit");
    Serial.println ("Jarak :");
    Serial.println (jarak);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Terapi 15 menit");
    lcd.setCursor(0,1);
    lcd.print("Jarak: ");
    lcd.setCursor(6,1);
    lcd.print(jarak);
    lcd.setCursor(14,1);
    lcd.print("cm");
    delay(1000);
  
    if(jarak<40 && jarak>34)
    {  
      for (int i=4 ; i>= 0 ; i--) {
      Serial.println("tunggu");  
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sisa Waktu : ");
      lcd.setCursor(14,0);
      lcd.print(i);
      lcd.setCursor(0,1);
      lcd.print("Jarak: ");
      lcd.setCursor(6,1);
      lcd.print(jarak);
      lcd.setCursor(14,1);
      lcd.print("cm");
      digitalWrite(lampu, LOW);
      delay(60000); 
    }
      digitalWrite(lampu, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
    }
    else
    {
      unsigned int uS = sonar.ping();
      float jarak=sonar.convert_cm(uS);
      Serial.println("kurang");
      delay(1000);
    }
  }

  else if (selectrs4 == HIGH)
  { 
    Serial.println ("Terapi 20 menit");
    Serial.println ("Jarak :");
    Serial.println (jarak);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Terapi 20 menit");
    lcd.setCursor(0,1);
    lcd.print("Jarak: ");
    lcd.setCursor(6,1);
    lcd.print(jarak);
    lcd.setCursor(14,1);
    lcd.print("cm");
    delay(1000);
  
    if(jarak<40 && jarak>34)
     {    
      for (int i=6 ; i>= 0 ; i--) {
      Serial.println("tunggu");  
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sisa Waktu : ");
      lcd.setCursor(14,0);
      lcd.print(i);
      lcd.setCursor(0,1);
      lcd.print("Jarak: ");
      lcd.setCursor(6,1);
      lcd.print(jarak);
      lcd.setCursor(14,1);
      lcd.print("cm");
      digitalWrite(lampu, LOW);
      delay(60000); 
      }
  
      digitalWrite(lampu, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
    }
    else
    {
      unsigned int uS = sonar.ping();
      float jarak=sonar.convert_cm(uS);
      Serial.println("kurang");
      delay(1000);
    }
  }
}
