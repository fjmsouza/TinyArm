// inclui bibilioteca do servomotor
#include <Servo.h>

// define pinos dos servos
#define pinServ1 3
#define pinServ2 5
#define pinServ3 6
#define pinServ4 9

// define as portas dos potenciometros
#define pot1 A0
#define pot2 A1
#define pot3 A2
#define pot4 A3

// nomeia os servos
Servo jointBase, jointRight, jointLeft, jointGrip;

// cria as variavies dos angulos de cada motor
int jointGradeBase, jointGradeLeft, jointGradeRight, jointGradeGrip;

unsigned long mostradorTimer = 1;
const unsigned long intervaloMostrador = 5000;

void setup() {

  //inicia o monitor serial
  Serial.begin(9600);

  // atribui pinos dos servos

  jointBase.attach(pinServ1);
  jointRight.attach(pinServ2);
  jointLeft.attach(pinServ3);
  jointGrip.attach(pinServ4);
}

void loop() {

  // leitura dos potenciometros
  jointGradeBase = map(analogRead(pot1), 0, 1023, 180, 0);
  jointGradeLeft = map(analogRead(pot3), 0, 1023, 85, 180);
  jointGradeRight = map(analogRead(pot2), 0, 1023, 180, 0);
  jointGradeGrip = map(analogRead(pot4), 0, 1023, 0, 180);

  // seta posicionamento dos servos
  jointBase.write(jointGradeBase);
  jointRight.write(jointGradeRight);
  jointLeft.write(jointGradeLeft);
  jointGrip.write(jointGradeGrip);

  if ((millis() - mostradorTimer) >= intervaloMostrador) {

    // envio para o monitor serial do posicionamentos dos motores
    Serial.println("**********************************************");

    Serial.print("Pot1:");
    Serial.print(analogRead(pot1));
    Serial.print(" Angulo Motor-Base:");
    Serial.println(jointGradeBase);

    Serial.print("Pot2:");
    Serial.print(analogRead(pot3));
    Serial.print(" Angulo Motor-Direito:");
    Serial.println(jointGradeRight);
    
    Serial.print("Pot3:");
    Serial.print(analogRead(pot2));
    Serial.print(" Angulo Motor-Esquerdo:");
    Serial.println(jointGradeLeft);

    mostradorTimer = millis();
  }

  // tempo de espera para recomeçar
  // delay(100); sem delay = sem ""tremedeira"
}
