#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

void state_advance(){
  
  if (sw_1){ /* first button play first song */
    song = &susanna[0];
    n = 32;
  } 
  if (sw_2){ /* second button play second song */
    song = &letItGo[0];
    n = 39;
  }
  if (sw_3){ /* third button play third song */
    song = &hakuna[0];
    n = 38;
  }
  if (sw_4){ /* fourth button play fourth song */
    song = &aladdin[0];
    n = 39; 
  }
}
void led_dim(){
  static int cnt = 0;
  static char state = 0; //red or green
  
  red_on = 0; //turn off red
  if(i>n){
    red_on = 1; //turn red on again
    green_on = 0; //turn green off
  }else if(i<3){
    green_on = 1; //constant green first 3 notes
  }else{
    switch (state) {
    case 0:
      if(cnt<1){ //on for 1
	green_on = 1;
	state = 1;
      }
      break;
    case 1: //off for 5
      green_on = 0;
      state = 0;
      break;
    }
    cnt++;
    if(cnt == 6){ //off for 5, on for 1
      cnt = 0;
    }
    }
  led_changed = 1;
  led_update();
}
