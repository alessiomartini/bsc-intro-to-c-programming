/**
 * Genera una tabella di conversione delle temperature
 * da Fahrenheit a Celsius
 *
 * Tratto, con adattamenti, da Kernighan, Ritchie: The
 * C programming language, Prentice Hall PTR.
 */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int   lower, upper, step;
    float fahr, celsius;

    lower = 0;    /* Valore minimo, in gradi F, della tabella  */
    upper = 300;  /* Valore massimo, in gradi F, della tabella */
    step  = 20;   /* Passo di incremento della tabella         */

    fahr = lower;

    while ( fahr <= upper )
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf ("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    exit(EXIT_SUCCESS);
}
