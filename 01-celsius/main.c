#include <stdio.h>

/* print farhrenheit table for fahr = 0,220, ... 300 */
int main() {

    int fahr, celsius; 
    int lower, upper, step;

    lower = 0; /* lower limit of temp scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("temp: %df, %dc\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}