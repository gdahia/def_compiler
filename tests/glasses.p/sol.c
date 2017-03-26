#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
void _fn_solve(int32_t a, int32_t b){
  int32_t its = 0;
  int32_t na = 0;
  int32_t nb = 0;

  while(its < 50 && a != b){
    _fn_print(a);
    _fn_print(b);
    _fn_print(-1);

    if(a > b){
      int32_t tmp = b;
      b = a;
      a = tmp;
    }

    na = 2*a;
    nb = b-a;

    a = na;
    b = nb;
    its = its+1;
  }

  if(a != b){
    _fn_print(-1);
  } else {
    _fn_print(its);
  }
}

void _fn_main(){
  _fn_solve(3, 3);
  _fn_solve(2, 6);
  _fn_solve(10, 6);
  _fn_solve(81, 15);
  _fn_solve(10, 11);
  _fn_solve(31002, 1290121);
  _fn_solve(49, 2);
  _fn_solve(1290381, 120121);
  _fn_solve(99999, 999);
}
/* END USER CODE */

int main(){ _fn_main(); }
