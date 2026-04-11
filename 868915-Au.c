// Aurelia Merola

#include <stdio.h>  //necessaria per le funzioni Input/Output
#include <stdlib.h> //necessaria per la funzione atoi
//#include <math.h>   //necessaria per le funzioni sqrt e pow
#include <string.h>

#define N 25    //definizione di una costante
#define T 86400 //definizione di una costante

struct Pacchetto
{
    int time;
    int deg;    //in ADU
    float temp; //Celsius
    char meteo[6];
};

float ADU_to_temp(int ADU)
{
    float temp;
    temp = (ADU * 160.0) / 255.0 - 50.0;
    return temp;
}

int main(int argc, char *argv[])
{
    //def di V vett di puntatori
    struct Pacchetto V[T];
    int i,a,b;
    float temp;

    for (i = 0; i < T; i++)
    {
        V[i].time = 0;
        
    }

    for (i = 0; i < N; i++)
    {
        //printf("QUI INIZIA SCANF\n");
        scanf("%dS%dT", &a, &b);
        //printf("QUI FINISCE SCANF\n");

        temp = ADU_to_temp(b);

        if (temp <= -14 && temp >= -22)
        {
            //V[a].meteo = "OMBRA";
            strcpy(V[a].meteo, "OMBRA");
        }
        else if (temp >= 74 && temp <= 82)
        {
            //V[a].meteo = "SOLE";
            strcpy(V[a].meteo, "SOLE");
        } else {
            continue;
        }
        
        V[a].deg = b;
        V[a].time = a;
        V[a].temp = temp;
    }

    for (i = 0; i < T; i++)
    {
        if (V[i].time != 0) {
            printf("%d  %f %s\n", V[i].time, V[i].temp, V[i].meteo);
        }
        
    }

    return EXIT_SUCCESS;
}
