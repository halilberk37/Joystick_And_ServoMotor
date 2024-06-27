#include <Servo.h>

Servo motor;

int xPin = A0;
int yPin = A1;
int SwPin =2;

int xPozisyonu = 0;
int yPozisyonu = 0;
int SwDurum = 0;
int toplam = 0;

void setup() {
Serial.begin(9600);
pinMode(xPin,INPUT);
pinMode(xPin,INPUT);
pinMode(SwPin,INPUT_PULLUP);
motor.attach(9);
}

void loop() {
xPozisyonu = analogRead(xPin);
yPozisyonu = analogRead(yPin);
toplam = xPozisyonu+yPozisyonu;
toplam = map(toplam,0,1010,0,180);
SwDurum = digitalRead(SwPin);

if(toplam >180){
  toplam=180;
}


motor.write(toplam);

Serial.print("X Pozisyonu:");
Serial.println(xPozisyonu);
Serial.print("Y Pozisyonu:");
Serial.println(yPozisyonu);
Serial.print("Buton Durum:");
Serial.println(SwDurum);
Serial.println(toplam);
delay(500);
}
