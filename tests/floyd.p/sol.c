#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t step = 0;
int32_t MOD = 0;

int32_t _fn_mod(int32_t x, int32_t MOD){
  int32_t q = x/MOD;
  return x-q*MOD;

return 0; // safe return
}

int32_t _fn_f(int32_t x){
  return _fn_mod(x*step, MOD);

return 0; // safe return
}

void _fn_solve(int32_t x, int32_t s, int32_t m){
  int32_t a = 0;
  int32_t b = 0;
  int32_t ans = 1;

  step = s;
  MOD = m;

  a = x;
  b = _fn_f(x);

  while(a != b){
    a = _fn_f(a);
    b = _fn_f(_fn_f(b));
  }

  b = _fn_f(b);
  while(a != b){
    b = _fn_f(b);
    ans = ans+1;
  }

  _fn_print(ans);
}

void _fn_main(){
  //_fn_solve(42, 2, 189281);
  _fn_solve(42, 2, 1892);
  _fn_solve(2, 3, 7);
  _fn_solve(56, 8081, 1991);
}
/* END USER CODE */

int main(){ _fn_main(); }
