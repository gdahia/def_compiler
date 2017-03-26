#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t MOD = 0;

// mod for positive numbers
int32_t _fn_mod(int32_t x){
  int32_t q = x/MOD;
  return x-q*MOD;

return 0; // safe return
}

int32_t _fn_f(int32_t f){
  if(f == 0) {return 0;}
  if(f == 1) {return _fn_mod(1);}
  return _fn_mod(_fn_f(f-1)+_fn_f(f-2));

return 0; // safe return
}

void _fn_solve(int32_t a, int32_t b){
  MOD = b;
  _fn_print(_fn_f(a));
}

void _fn_main(){
  int32_t i = 0;
  _fn_solve(1, 1);
  _fn_solve(10, 10);
  _fn_solve(17, 21);
  _fn_solve(15, 1000000);

  while(i <= 10){
    _fn_solve(i, 10000);
    i = i+1;
  }
}
/* END USER CODE */

int main(){ _fn_main(); }
