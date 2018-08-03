#include <AFMotor.h>
bool isOpen =false;
String inputString = "";      
boolean stringComplete = false; 
int speedOutput = 0;


AF_DCMotor motor_Left(1);  
AF_DCMotor motor_Right(2);     
AF_DCMotor valvula(3); 

void setup() {
   Serial.begin(9600);
   Serial.println("Start Program");  
   inputString.reserve(200);
   motor_Left.setSpeed(0);
   motor_Right.setSpeed(0);
   valvula.run(FORWARD);
   valvula.setSpeed(0);
}

void loop() {
    if(isOpen){
      valvula.setSpeed(speedOutput);
      Serial.println("Valvula value");
      Serial.println(speedOutput);
    }else{
      Serial.println("Valvula is close");
      valvula.setSpeed(0);
    }
}

void serialEvent() {
    while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    switch(inChar){
      // Adelante
      case 'w':
        Serial.println("Adelante");
        motor_Left.run(BACKWARD);
        motor_Right.run(FORWARD);
        motor_Left.setSpeed(255);
        motor_Right.setSpeed(255);
      break;
      case 's':
        Serial.println("atras");
        motor_Left.run(FORWARD);
        motor_Right.run(BACKWARD);
        motor_Left.setSpeed(255);
        motor_Right.setSpeed(255);
      break;
      case 'd':
        Serial.println("derecha");
        motor_Left.run(BACKWARD);
        motor_Right.run(BACKWARD);
        motor_Left.setSpeed(255);
        motor_Right.setSpeed(255);
      break;
      case 'a':
        Serial.println("izquierda");
        motor_Left.run(FORWARD);
        motor_Right.run(FORWARD);
        motor_Left.setSpeed(255);
        motor_Right.setSpeed(255);
      break;
      case 'f':
        Serial.println("parar");
        motor_Left.setSpeed(0);
        motor_Right.setSpeed(0);
        valvula.setSpeed(0);
      break;
      case 'g':
        Serial.println("open");
        isOpen = true;
      break;
      case 'h':
        Serial.println("close");
        isOpen=false;
        speedOutput = 0;
      break;
      case 'j':
        Serial.println("Subir presion");
        if(speedOutput < 125)
          speedOutput = 125;
        
        speedOutput = speedOutput + 1;

        if (speedOutput > 255)
         speedOutput = 255; 
      break;
       case 'k':
        Serial.println("Bajar presion");
        speedOutput = speedOutput - 1;
        if(speedOutput < 125)
          speedOutput = 0;
        break;
    }
    Serial.flush();
  }
}

