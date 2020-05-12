#include "simpletools.h"
#include "datetime.h"                    // Include simpletools header

// Button                              
int ButtonList[2000];
int PINBUTTON = 3;

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
                                   
  while((end_time) > (dt_getms()))    //hier bepalen hoelang
  {
    
    int button = input(PINBUTTON)            //voeg 1 of 0 toe aan een lijst
    print("Button : %d \n", button);
    ButtonList[index] = button;
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
  while(1)   
  {
    int button = input(PINBUTTON)              //voeg 1 of 0 toe aan een lijst
    print("Button : %d \n", button);
  } 
}
