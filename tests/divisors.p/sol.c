#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t _fn_mod(int32_t x, int32_t MOD){
  int32_t q = x/MOD;
  return x-q*MOD;

return 0; // safe return
}

void _fn_solve(int32_t x){ // for x > 0
  int32_t i = 1;
  while(i*i <= x){
    if(!_fn_mod(x, i)){
      _fn_print(i);
      if(i*i != x){
        _fn_print(x/i);
      }
    }

    i = i+1;
  }

  _fn_print(-1);
}

void _fn_main(){
  _fn_solve(8);
  _fn_solve(81);
  _fn_solve(47);
  _fn_solve(42);
  _fn_solve(56);
}
/* END USER CODE */

int main(){ _fn_main(); }
