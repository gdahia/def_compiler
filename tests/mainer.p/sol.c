#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t a = 0;

int32_t _fn_main() {
    if (a == 10) {
        _fn_print(a);
    }
    else {
        a = a + 1;
        _fn_main();
        _fn_print(a);
    }

return 0; // safe return
}
/* END USER CODE */

int main(){ _fn_main(); }
