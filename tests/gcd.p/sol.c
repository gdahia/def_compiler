#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t _fn_mod(int32_t x, int32_t MOD){
  int32_t q = x/MOD;
  return x-q*MOD;

return 0; // safe return
}

int32_t _fn_gcd(int32_t a, int32_t b){
  if(b == 0){
    return a;
  }

  return _fn_gcd(b, _fn_mod(a,b));

return 0; // safe return
}

int32_t _fn_main(){
  _fn_print(_fn_gcd(42, 21));
  _fn_print(_fn_gcd(259912, 1902931));
  _fn_print(_fn_gcd(1, 0));
  _fn_print(_fn_gcd(42, 42));
  _fn_print(_fn_gcd(0, 0));
  _fn_print(_fn_gcd(42, 56));

return 0; // safe return
}
/* END USER CODE */

int main(){ _fn_main(); }
