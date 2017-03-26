#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
void _fn_solve(int32_t a, int32_t b){
  int32_t i = 0;
  while(a <= b){
    a = a*3;
    b = b*2;
    i = i+1;
  }

  _fn_print(i);
}

void _fn_main(){
  _fn_solve(2, 10);
  _fn_solve(47, 192039102);
  _fn_solve(1, 100000000);
  _fn_solve(1291, 1291902);
  _fn_solve(4, 7);
  _fn_solve(4, 9);
  _fn_solve(1, 1);
}
/* END USER CODE */

int main(){ _fn_main(); }
