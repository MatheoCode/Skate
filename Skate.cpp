#include <SoftwareSerial.h>
#include <Servo.h>
Servo esc;

SoftwareSerial mySerial(10, 11); 
int valeur;


void setup()
{
  Serial.begin(9600); 
  mySerial.begin(9600);
  esc.attach(8);
  esc.write(0);
  delay(1000);
  esc.write(180);
  delay(1000);
  esc.write(0);
}

void loop() 
{ 
  if (mySerial.available()) 
  {
    valeur = mySerial.read();
    Serial.print(valeur);
    valeur = map(valeur, 0, 25, 100, 162);
    Serial.print("   ");
    Serial.println(valeur);
    esc.write(valeur);
  }
}
