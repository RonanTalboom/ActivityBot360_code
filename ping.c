/*
  Test Ping.c

  Test the PING))) sensor before using it to navigate with the ActivityBot.

  http://learn.parallax.com/activitybot/build-and-test-ping-sensor-circuit
*/

#include "simpletools.h"  
#include "datetime.h"                    // Include simpletools header
#include "ping.h"                             // Include ping header

int distance;                              // Declare distance variable
int distanceList[2000];
int pinNumber = 8;
float waitms;
int echoList[1000];

int main()                                    // main function
{    
  //measureForTimems(2000);
  //keepmeasuring();
  pingEcho(2000);
 
}
void measureForTimems(int ms){
  print("meeten voor %d seconden ....", ms/1000);
  int initial = dt_getms();
  int plus = initial + ms; 
  int index = 0; 
  
  while((plus) > (dt_getms()))    //hier bepalen hoelang                              
  {
    //@brief Measure echo time in terms of Propeller system clock ticks.
    distance = ping_cm(pinNumber); 
    //print("dist : %d \n", distance);            
    distanceList[index] = distance;
    index++; 
    pause(200);                       
  } 
   
  //Frequentie(meting) hoe vaak die meet en Time(s) hoelang die heeft gemeten
  // ms -> s = /1000;
  // HZ = F/T

  int HZ = index / (ms/1000);
  int sum = 0;
  for(int i = 0; i < index; i++)
  {
    sum += distanceList[i];
    
    printf("distance = %d cm \n",            // Display distance
           distanceList[i]); 
  } 
  int av = (sum / index);  
  print("av : %d cm \n", av);
  print("HZ : %d hz \n", HZ);
  
  

}  
void keepmeasuring(){

  while(1)    //hier bepalen hoelang                              
  {
    //@brief Measure echo time in terms of Propeller system clock ticks.
    distance = ping_cm(pinNumber); 
    print("dist : %d \n", distance);            
                         
  } 
}  
  void pingEcho(int ms){
    
  int initial = dt_getms();
  int plus = initial + ms; 
  int index = 0; 
  while((plus) > (dt_getms()))   
   {
     distance = ping_cm(pinNumber);
     print("%c distance = %d%c cm",            // Display distance
           HOME, distance, CLREOL);           
     distance = ping(pinNumber);
    
     print("\n echo time = %d%c us", distance, CLREOL);
     echoList[index] = distance;
     waitms = distance / 1000;
     
     pause(waitms);
     index++;
}
  int HZ = index / (ms/1000);
  int sum = 0;
  for(int i = 0; i < index; i++)
  {
    sum += echoList[i];
    
    printf("echo = %d us \n",            // Display distance
           echoList[i]); 
  } 
  int av = (sum / index);  
  print("av : %d us \n", av);
  print("HZ : %d hz \n", HZ);
}  

