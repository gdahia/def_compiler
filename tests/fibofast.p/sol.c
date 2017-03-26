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
  int32_t a = 0;
  int32_t b = 0;
  int32_t i = 0;

  if(f == 0) {
    return _fn_mod(0);
  }

  if(f == 1) {
    return _fn_mod(1);
  }

  a = 0;
  b = 1;
  i = 1;
  while(i < f){
    int32_t tmp = b;
    b = a+b;
    a = tmp;
    i = i+1;
  }

  return b;

return 0; // safe return
}

void _fn_solve(int32_t a, int32_t b){
  MOD = b;
  _fn_print(_fn_f(a));
}

void _fn_main(){
  int32_t i = 0;

  _fn_solve(1, 1);
  _fn_solve(5, 100);
  _fn_solve(22, 21);
  _fn_solve(21, 1000000);
  _fn_solve(30, 1021037); 

}
/* END USER CODE */

int main(){ _fn_main(); }
