/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "abdrive360.h"
#include "math.h"

int main()                                    // Main function
{
  // Add startup code here.
  drive(-40);
  turn(90);   
}  

int convertCmToTick (int cm){
 return (cm * 10) / 3.25;
 
}  
 
double convertDegreesToTicks(int degrees){
  return ((664.76/ 360) * degrees) / 3.25;
  
}
void drive(int cm){
  int ticks = convertCmToTick(cm);
  drive_goto(ticks,ticks);
} 

void turn(int degree){
  double degreeticks = convertDegreesToTicks(degree) / 2;
  drive_goto( ceil(degreeticks), (floor(degreeticks) * -1));  
 }
 
