#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t _fn_mod(int32_t x, int32_t MOD){
  int32_t q = x/MOD;
  return x - q*MOD;

return 0; // safe return
}

int32_t _fn_phi(int32_t n){
  int32_t res = n;
  int32_t i = 2;
  while(i*i <= n){
    if(_fn_mod(n, i) == 0){
      while(_fn_mod(n, i) == 0){
        n = n/i;
      }
      res = res - res/i;
    }

    i = i+1;
  }

  if(n > 1){
    res = res - res/n;
  }

  return res;

return 0; // safe return
}

void _fn_solve(int32_t x){
  _fn_print(_fn_phi(x));
}

void _fn_main(){
  _fn_solve(42);
  _fn_solve(56);
  _fn_solve(20910921);
  _fn_solve(1717171);
  _fn_solve(97);
  _fn_solve(1024);
}
/* END USER CODE */

int main(){ _fn_main(); }
