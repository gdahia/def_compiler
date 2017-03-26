#include "stdio.h"
#include "stdint.h"
void _fn_print(int32_t x) { printf("%d\n", x); }

/* BEGIN USER CODE */
int32_t _fn_f(int32_t a, int32_t b) {
    if (a == 3) {
        int32_t a = 10 * b;
        while (a > 3) {
            int32_t b = 2;
            a = a / b;
        }
    }
    else {
        int32_t b = a * 3;
        while (b > a) {
            int32_t a = 4;
            b = b / a;
        }
    }
    return a;

return 0; // safe return
}

int32_t _fn_main() {
    _fn_print(_fn_f(7, 5));

return 0; // safe return
}
/* END USER CODE */

int main(){ _fn_main(); }
