#include "simpletools.h"
#include "datetime.h"                    // Include simpletools header

// IRLED 
int IR;                              
int IRList[2000];
int PINIR = 10;
int PINLEDIR = 1;
int FREQUENTIE = 38000;
int TERMINALZEROV = 27;

int main()                                    // main function
{ 
  loopForTimems(3000);
  //keepmeasuring();
}
 
void loopForTimems(int ms){
  print("meten voor %d seconden ....", ms/1000);
  
  int initial_ms = dt_getms();
  int end_time = initial_ms + ms; 
  int index = 1; //starten op 1 omdat we lui zijn en voor de lengte.
                                   
  low(27);                        // D/A0 & D/A1 to 0 V
  while((end_time) > (dt_getms()))    //hier bepalen hoelang
  {
    freqout(PINLEDIR, 1,FREQUENTIE);
    IR = input(PINIR);                   //voeg 1 of 0 toe aan een lijst
    print("IR : %d \n", IR);
    IRList[index] = IR;
    index++;
  } 

  //Frequentie(meting) hoe vaak die meet en Time(s) hoelang die heeft gemeten
  // ms -> s = /1000;
  // HZ = F/T

  int HZ = index / (ms/1000);
  print("index : %d \n", index);
  print("HZ : %d hz \n", HZ);

}
void keepmeasuring(){
  low(27);
  while(1)   
  {
    freqout(PINLEDIR, 1,FREQUENTIE);
    IR = input(PINIR);
    print("IR : %d \n", IR);
  } 
}
