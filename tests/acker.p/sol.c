#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t _fn_alpha(int32_t n, int32_t m){
  if(m == 0){
    return n+1;
  }

  if(n == 0){
    return _fn_alpha(1, m-1);
  }

  return _fn_alpha(_fn_alpha(n-1, m), m-1);

return 0; // safe return
}

void _fn_solve(int32_t x){
  _fn_print(_fn_alpha(x, x));
}

void _fn_main(){
  _fn_solve(3);
  _fn_solve(1);
  _fn_solve(2);
}
/* END USER CODE */

int main(){ _fn_main(); }
