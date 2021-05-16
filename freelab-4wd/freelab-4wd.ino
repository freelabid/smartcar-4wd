#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 

// You should get Auth Token in the Blynk App. 
// Go to the Project Settings (nut icon). 
char auth[] = "lOsfwbSCLLfd_iBDNaNYfYJYHE9WBTFS"; 

// Your WiFi credentials. 
// Set password to "" for open networks. 
char ssid[] = "Lodewijk"; 
char pass[] = "hgaloeng";  

int PWMA=D0; //Right side 
int PWMB=D2; //Left side 
int DA=D1; //Right reverse 
int DB=D3; //Left reverse 

int MAX_PWM_VOLTAGE = 50;

void setup() {
     Serial.begin(9600); 
     Blynk.begin(auth, ssid, pass); 
     pinMode(PWMA, OUTPUT);
     pinMode(PWMB, OUTPUT);
     pinMode(DA, OUTPUT);
     pinMode(DB, OUTPUT);
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
