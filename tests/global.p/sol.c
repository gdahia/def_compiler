#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t glob = 0;

int32_t _fn_go(int32_t x, int32_t y){
  _fn_print(glob);
  glob = glob+x*x;
  return glob/4+5+y;

return 0; // safe return
}

void _fn_main(){
  _fn_print(_fn_go(_fn_go(_fn_go(5, 42), _fn_go(10, _fn_go(5, 2))), 0));
}
/* END USER CODE */

int main(){ _fn_main(); }
