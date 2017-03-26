#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t _fn_mod(int32_t x, int32_t MOD){
  return x-x/MOD*MOD;

return 0; // safe return
}

int32_t _fn_power(int32_t x, int32_t p, int32_t MOD){
  int32_t res = 0;
  if(p == 0) {
    return _fn_mod(1, MOD);
  }
  if(p == 1){
    return _fn_mod(x, MOD);
  }
  res = _fn_power(x, p/2, MOD);
  res = _fn_mod(res*res, MOD);
  if(_fn_mod(p, 2) == 1){
    res = _fn_mod(res*_fn_mod(x, MOD), MOD);
  }

  return res;

return 0; // safe return
}

void _fn_solve(int32_t x, int32_t p, int32_t MOD){
  _fn_print(_fn_power(x, p, MOD));
}

void _fn_main(){
  _fn_solve(42, 19212001, 10212);
  _fn_solve(56, 9910291, 1290);
  _fn_solve(109290192, 920190219, 20102);
}
/* END USER CODE */

int main(){ _fn_main(); }
