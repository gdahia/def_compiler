#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t _fn_fat(int32_t n) {
    if (n <= 0) {
        return 1;
    }
    return n * _fn_fat(n - 1);

return 0; // safe return
}

int32_t f = _fn_fat(6);

int32_t _fn_main() {
    _fn_print(f);

return 0; // safe return
}
/* END USER CODE */

int main(){ _fn_main(); }
