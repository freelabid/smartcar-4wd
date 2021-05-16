/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Social networks:            http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use ESP32 BT
  to connect your project to Blynk.

  Warning: Bluetooth support is in beta!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define BLYNK_USE_DIRECT_CONNECT

#include <BlynkSimpleEsp32_BT.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "esAFA_k6K5uDgnZi9pg2xeetMNG87j31";

int PWMA=13; //Right side 
int PWMB=14; //Left side 
int DA=12; //Right reverse 
int DB=27; //Left reverse 

int MAX_PWM_VOLTAGE = 50;

void setup() {
     Serial.begin(9600); 
     Serial.println("Waiting for connections...");
     pinMode(PWMA, OUTPUT);
     pinMode(PWMB, OUTPUT);
     pinMode(DA, OUTPUT);
     pinMode(DB, OUTPUT);
     Blynk.setDeviceName("Freelab4WD");
     Blynk.begin(auth); 
}

void loop(){
     Blynk.run();
}

// Handling Joystick data 
BLYNK_WRITE(V1) {
     int x = param[0].asInt(); 
     int y = param[1].asInt();
     if(x==-1 && y==-1){             //Backward and Left     
          Serial.println("BL");
          digitalWrite(PWMA, LOW); 
          digitalWrite(DA, MAX_PWM_VOLTAGE); 
          
          digitalWrite(PWMB, LOW); 
          digitalWrite(DB, LOW); 
     } else if(x==1 && y==0){
          Serial.println("R");
          digitalWrite(PWMA, LOW); 
          digitalWrite(DA, MAX_PWM_VOLTAGE); 
         
          digitalWrite(PWMB, MAX_PWM_VOLTAGE); 
          digitalWrite(DB, LOW); 
     } else if(x==1 && y==1){     
          Serial.println("FR");
          digitalWrite(PWMA, LOW); 
          digitalWrite(DA, LOW); 
         
          digitalWrite(PWMB, MAX_PWM_VOLTAGE); 
          digitalWrite(DB, LOW); 
     } else if(x==0 && y==-1){        //Backward     
          Serial.println("B");
          digitalWrite(PWMA, LOW); 
          digitalWrite(DA, MAX_PWM_VOLTAGE); 
          
          digitalWrite(PWMB, LOW); 
          digitalWrite(DB, MAX_PWM_VOLTAGE);
     } else if(x==0 && y==0){        //Stay 
          Serial.println("S");
          digitalWrite(PWMA, LOW); 
          digitalWrite(DA, LOW); 
          
          digitalWrite(PWMB, LOW); 
          digitalWrite(DB, LOW); 
     } else if(x==0 && y==1){        //Forward 
          Serial.println("F");
          digitalWrite(PWMA, MAX_PWM_VOLTAGE); 
          digitalWrite(DA, LOW); 
         
          digitalWrite(PWMB, MAX_PWM_VOLTAGE); 
          digitalWrite(DB, LOW); 
     } else if(x==1 && y==-1){        //Backward and Right     
          Serial.println("BR");
          digitalWrite(PWMA, LOW); 
          digitalWrite(DA, LOW); 
          
          digitalWrite(PWMB, LOW); 
          digitalWrite(DB, MAX_PWM_VOLTAGE);
     } else if(x==-1 && y==0){
          Serial.println("L");
          digitalWrite(PWMA, MAX_PWM_VOLTAGE); 
          digitalWrite(DA, LOW); 
          
          digitalWrite(PWMB, LOW); 
          digitalWrite(DB, MAX_PWM_VOLTAGE); 
     } else if(x==-1 && y==1){ 
          Serial.println("FL");
          digitalWrite(PWMA, HIGH); 
          digitalWrite(DA, LOW); 
          
          digitalWrite(PWMB, LOW); 
          digitalWrite(DB, LOW);
     } 
}
