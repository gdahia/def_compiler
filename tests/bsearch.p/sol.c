#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t MX = 0;

void _fn_solve(int32_t x){
  int32_t l = 0;
  int32_t r = MX;
  while(l < r){
    int32_t mid = (l+r)/2;
    if(mid*(mid+1)/2 >= x){
      r = mid;
    } else {
      l = mid+1;
    }
  }

  _fn_print(l);
}

void _fn_main(){
  int32_t i = 1;
  while(i*i < 1000000000){
    i = i+1;
  }

  MX = i;

  _fn_solve(42);
  _fn_solve(109092190);
  _fn_solve(999999999);
  _fn_solve(80475327);
  _fn_solve(424242424);
  _fn_solve(24242424);
  _fn_solve(199999289);
}
/* END USER CODE */

int main(){ _fn_main(); }
