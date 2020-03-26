#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char second_count = 0;
  if (++second_count == 50 && i<=n) { //note length
    play_notes();
    second_count = 0;
  }
  if (i<=n+1){
    led_dim();
  }
}
