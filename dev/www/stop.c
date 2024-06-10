#include <stdio.h>
#include <wiringPi.h>

//install WiringPi

#define motorA_1 0
#define motorA_2 1
#define motorB_1 2
#define motorB_2 3

void stop(){
    digitalWrite (motorA_1, LOW);
    digitalWrite (motorB_1, LOW);
    digitalWrite (motorA_2, LOW);
    digitalWrite (motorB_2, LOW);
}


void main(){
wiringPiSetup () ;
pinMode (motorA_1, OUTPUT) ;
pinMode (motorA_2, OUTPUT) ;
pinMode (motorB_1, OUTPUT) ;
pinMode (motorB_2, OUTPUT) ;

stop();

}
