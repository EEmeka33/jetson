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


int motorA_1 = 16;
int motorA_2 = 18;
int motorB_1 = 22;
int motorB_2 = 24;

//         avant
//gauche A tank B droite
//        arriere

void stop(){
    GPIO::output(motorA_1, GPIO::LOW);
    GPIO::output(motorB_1, GPIO::LOW);
    GPIO::output(motorA_2, GPIO::LOW);
    GPIO::output(motorB_2, GPIO::LOW);
}
void avancer(){
    GPIO::output(motorA_1, GPIO::HIGH);
    GPIO::output(motorB_1, GPIO::HIGH);
    GPIO::output(motorA_2, GPIO::LOW);
    GPIO::output(motorB_2, GPIO::LOW);
}
void reculer(){
    GPIO::output(motorA_1, GPIO::LOW);
    GPIO::output(motorB_1, GPIO::LOW);
    GPIO::output(motorA_2, GPIO::HIGH);
    GPIO::output(motorB_2, GPIO::HIGH);
    
}
void gauche(){
    GPIO::output(motorA_1, GPIO::LOW);
    GPIO::output(motorB_1, GPIO::HIGH);
    GPIO::output(motorA_2, GPIO::HIGH);
    GPIO::output(motorB_2, GPIO::LOW);
    
}
void droite(){
    GPIO::output(motorA_1, GPIO::HIGH);
    GPIO::output(motorB_1, GPIO::LOW);
    GPIO::output(motorA_2, GPIO::LOW);
    GPIO::output(motorB_2, GPIO::HIGH);
    
}

int main( int argc, char** argv ) {
printf( "Content-Type: text/plain\n" );
printf( "\n" );
char* query = getenv( "QUERY_STRING" );
if(query[0]=='a'){
    avancer();
    sleep(1);
}
if(query[0]=='r'){
    reculer();
    sleep(1);
}
if(query[0]=='g'){
    gauche();
    sleep(1);
}
if(query[0]=='d'){
    droite();
    sleep(1);
}
if(query[0]=='s'){
    stop();
    sleep(1);
}
return 0;
}
