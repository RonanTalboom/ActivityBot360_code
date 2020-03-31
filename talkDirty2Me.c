/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "stdint.h"
#include "text2speech.h"
#include "sound.h"
#include "wavplayer.h"


talk* talk1;

int main()                                    // Main function
{
  // Add startup code here.
  
 talk1 = talk_run(4,-1) ;

 talk_set_speaker(talk1, 1, 100);
// talk_say(talk1,"Jason;deroolo");
 talk_say(talk1,"ahp, 'nahr, 'weereld, 'dhoamenatee");
 pause(1000);
 talk_say(talk1,"coroanah");
  pause(1000);
 talk_end(talk1);
  pause(1000);
  print("wereld dominatie door coRonan the destroyer ");
 
 int DO = 22, CLK = 23, DI = 24, CS = 25;        // SD I/O pins
 sd_mount(DO, CLK, DI, CS);                      // Mount SD card
 
 const char bird[] = {"FLUIT1.wav"};
 const char bird2[] = {"FLUIT2.wav"};
  wav_set_pins(4,-1); 
 wav_play(bird);  
 wav_volume(10);     
  pause(3000);                                              
 wav_stop(); 
 wav_play(bird2);  
 wav_volume(10);     
  pause(3000);                                              
 wav_stop(); 
 print("\nbirdie 1"); 

 
}
