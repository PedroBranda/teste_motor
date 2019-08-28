#include <DC_Motor.h>

#define AI2 16        //D0
#define AI1  5         //D1 
#define BI1  4         //D2
#define BI2  0         //D3
#define PWM_A 14 //D5
#define PWM_B 12 //D6

int vel = 50;
//DC_Motor motorDireito(AI1, AI2, PWM_A);
//DC_Motor motorEsquerdo(BI1, BI2, PWM_B);

void setup()
{
  pinMode(AI2, OUTPUT);
  pinMode(AI1, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);
  pinMode(PWM_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()) {
    motorDireito.velocidade(vel);
    motorEsquerdo.velocidade(vel);
    char c = Serial.read();
    if (c == 'w') {
      //motorDireito.horario();
      digitalWrite(AI1, true);
      digitalWrite(AI2, false);
      //motorEsquerdo.horario();
      digitalWrite(BI1, true);
      digitalWrite(BI2, false);
    
    }
   else  if (c == 'a'){
      //motorDireito.horario();
      digitalWrite(AI1, true);
      digitalWrite(AI2, false);
      //motorEsquerdo.parar();
      digitalWrite(BI1, false);
      digitalWrite(BI2, false);
    }
    else if (c == 's') {
      //motorDireito.antiHorario();
      digitalWrite(AI1, false);
      digitalWrite(AI2, true);
      //motorEsquerdo.antiHorario();
      digitalWrite(BI1, false);
      digitalWrite(BI2, true);
    }
    else if (c == 'd') {
      //motorDireito.parar();
      digitalWrite(AI1, false);
      digitalWrite(AI2, false);
      //motorEsquerdo.horario();
      digitalWrite(BI1, true);
      digitalWrite(BI2, false);
    }
    else if (c == 'r') {
      //motorDireito.parar();
      digitalWrite(AI1, false);
      digitalWrite(AI2, false);
      //motorEsquerdo.parar();
      digitalWrite(BI1, false);
      digitalWrite(BI2, false);
    }
    analogWrite(PWM_A, vel);
    analogWrite(PWM_B, vel);
  }
}
