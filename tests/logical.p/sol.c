#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
void _fn_solve(int32_t x, int32_t y){
  _fn_print(x+y*((x > 42) + (8 && y)));
  _fn_print(y/x || -(-42 < -x) + -!!!-49181*5656);
}

void _fn_main(){
  _fn_solve(42, 56);
  _fn_solve(56, 42);
  _fn_solve(112121, 21921920);
}
/* END USER CODE */

int main(){ _fn_main(); }
