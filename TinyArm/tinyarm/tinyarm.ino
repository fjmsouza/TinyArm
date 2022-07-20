// inclui bibilioteca do servomotor
#include <Servo.h>

// define pinos dos servos
#define pinServ1 3
#define pinServ2 5
#define pinServ3 6

// define as portas dos potenciometros
#define pot1 A0
#define pot2 A1
#define pot3 A2


#define intervalo 500

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
}

void loop() {

  // leitura dos potenciometros
  // jointGradeBase = map(analogRead(pot1), 0, 1023, 180, 0);
  // jointGradeLeft = map(analogRead(pot3), 0, 1023, 85, 180);
  // jointGradeRight = map(analogRead(pot2), 0, 1023, 180, 0);

  // seta posicionamento dos servos
  // jointBase.write(jointGradeBase);
  // jointRight.write(jointGradeRight);
  // jointLeft.write(jointGradeLeft);

  

  // tempo de espera para recomeçar
  // delay(100); sem delay = sem ""tremedeira"

  home();
  
  posicaoSeguranca();
  teclaUm();
  teclaTres();
  teclaQuatro();
  
}

void teclaUm(){

  jointBase.write(100);
  jointRight.write(168);
  jointLeft.write(141);
  delay(intervalo);

  jointBase.write(100);
  jointRight.write(168);
  jointLeft.write(124);
  delay(intervalo);

  jointBase.write(100);
  jointRight.write(168);
  jointLeft.write(141);
  delay(intervalo);

}

void teclaTres(){

  jointBase.write(86);
  jointRight.write(170);
  jointLeft.write(143);
  delay(intervalo);

  jointBase.write(86);
  jointRight.write(170);
  jointLeft.write(130);
  delay(intervalo);

  jointBase.write(86);
  jointRight.write(170);
  jointLeft.write(143);
  delay(intervalo);

}

void teclaQuatro(){

  jointBase.write(103);
  jointRight.write(155);
  jointLeft.write(131);
  delay(intervalo);

  jointBase.write(103);
  jointRight.write(155);
  jointLeft.write(111);
  delay(intervalo);

  jointBase.write(103);
  jointRight.write(155);
  jointLeft.write(131);
  delay(intervalo);

}


void posicaoSeguranca(){

  jointBase.write(94);
  jointRight.write(127);
  jointLeft.write(118);
  delay(intervalo);
}

void home(){

  jointBase.write(94);
  jointRight.write(86);
  jointLeft.write(180);
  delay(intervalo);
}
