#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
// bruteforce sequences such that adjacent elements x, y are such that |x-y| <= K
int32_t K = 0;
int32_t n = 0;
int32_t lo = 0;
int32_t hi = 0;

int32_t _fn_brute(int32_t last, int32_t len){
  int32_t i = 0;
  int32_t res = 0;
  if(len == n){
    return 1;
  }

  i = last-K;
  while(i <= last+K){
    if(i >= lo && i <= hi){
      res = res + _fn_brute(i, len+1);
    }
    i = i+1;
  }

  return res;

return 0; // safe return
}

void _fn_solve(int32_t a, int32_t b, int32_t c, int32_t d){
  int32_t res = 0;
  int32_t i = 0;

  n = a;
  K = b;
  lo = c;
  hi = d;

  i = lo;
  while(i <= hi){
    res = res + _fn_brute(i, 1);
    i = i+1;
  }

  _fn_print(res);
}

void _fn_main(){
  _fn_solve(5, 2, 17, 22);
  _fn_solve(3, 3, 42, 56);
  _fn_solve(8, 1, 3, 8);
  _fn_solve(2, 10, 99, 119);
}
/* END USER CODE */

int main(){ _fn_main(); }
