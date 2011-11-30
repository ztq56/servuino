//================================================
//  Servuino 
//  Developed by Benny Saxen, ADCAJO
//================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

#define ANAPINS 6
#define DIGPINS 14
#define INTPINS 2

#define LOW    0
#define HIGH   1
#define INPUT  1
#define OUTPUT 2

#define BYTE   1
#define BIN    2
#define OCT    3
#define DEC    4
#define HEX    5

#define CHANGE  1
#define RISING  2
#define FALLING 3
#define STEP_MAX  100
#define LOOP_MAX  200

#define DP 5
#define AP 15
#define RF 0
#define ER 1
#define SR 20

#define ON     1
#define OFF    0

#define YES    1
#define NO     2


char sketch[80];

// Init

int timeFromStart = 0;
int g_simulationLength = 111;
int g_go = NO;

void (*interrupt0)();
void (*interrupt1)();

void stepCommand();

FILE *s_log,*e_log;


#include "servuino_lib.c"
#include "arduino_lib.c"
#include "sketch.pde"

//====================================
void runEncoding(int n)
//====================================
{
  boardInit();
  readScenario();
  //printf("Servuino Encoder Version 0.0.4\n");
  fprintf(s_log,"# SCENARIODATA %d %d %d\n",scenDigital,scenAnalog,scenInterrupt);
  scenario();
  status();
  fprintf(s_log,"# LOOP %d\n",g_nloop);
  setup();
  while(1)
    {
      g_nloop++;
      status();
      fprintf(s_log,"# LOOP %d\n",g_nloop);
      loop();  
    }
  return;
}


//====================================
int main(int argc, char *argv[])
//====================================
{
  g_go = YES;
  openSimFile();
  readSketchInfo();
  if(argc == 2) g_simulationLength = atoi(argv[1]);
  runEncoding(g_simulationLength);
  closeSimFile();

}


 