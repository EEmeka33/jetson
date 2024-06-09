#include <stdlib.h>
#include <stdio.h>
// Handles input and output
#include <iostream>
 
// For delay function
#include <chrono> 
 
// Handles threads of program execution
#include <thread>
 
// Signal handling
#include <signal.h>
// Signal handling
#include <JetsonGPIO.h>
#include <unistd.h>


int motorA_1 = 37;
int motorA_2 = 35;
int motorB_1 = 33;
int motorB_2 = 31;

//         avant
//gauche A tank B droite
//        arriere


void avancer(){
    GPIO::output(motorA_1, GPIO::HIGH);
    GPIO::output(motorB_1, GPIO::HIGH);
    GPIO::output(motorA_2, GPIO::LOW);
    GPIO::output(motorB_2, GPIO::LOW);
}

int main( int argc, char** argv ) {
GPIO::setmode(GPIO::BOARD);
  GPIO::setup(motorA_1, GPIO::OUT, GPIO::LOW);
  GPIO::setup(motorA_2, GPIO::OUT, GPIO::LOW);
  GPIO::setup(motorB_1, GPIO::OUT, GPIO::LOW);
  GPIO::setup(motorB_2, GPIO::OUT, GPIO::LOW);
GPIO::setup(7, GPIO::OUT, GPIO::LOW);
printf( "Content-Type: text/plain\n" );
printf( "\n" );
char* query = getenv( "QUERY_STRING" );

avancer();
int truc = 0;
GPIO::output(7, GPIO::HIGH);
while(truc <= 1000000000){
truc+=1;
}
GPIO::output(7, GPIO::LOW);
return 0;
}
