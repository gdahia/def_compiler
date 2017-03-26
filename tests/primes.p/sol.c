#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t _fn_mod(int32_t x, int32_t MOD){
  int32_t q = x/MOD;
  return x-q*MOD;

return 0; // safe return
}

int32_t _fn_count(int32_t n){
  int32_t i = 0;

  if(n == 1){
    return 0;
  }

  i = 2;
  while(i < n && _fn_mod(n, i)){
    i = i+1;
  }

  while(_fn_mod(n, i) == 0){
    n = n/i;
  }

  return 1+_fn_count(n);

return 0; // safe return
}

void _fn_solve(int32_t x){
  _fn_print(_fn_count(x));
}

void _fn_main(){
  _fn_solve(42);
  //_fn_solve(96);
  //_fn_solve(1);
  //_fn_solve(56);
  //_fn_solve(47);
}
/* END USER CODE */

int main(){ _fn_main(); }
