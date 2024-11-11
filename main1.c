#include <stdio.h>
#include <stdlib.h>
//#include "matrix_vector.h"

//Funktiondefine
double teileIntervall(double schrittweite, double intervall[]);
double** euler(double (*funktion)(double, double),double schrittweite, double intervall[], double anfangswert[]);
int ergToFile(double** erg, char name[], int anzahlzeilen);

double fun1(double t,double y)
{
    double f;
    f=(9.0/4.0)*y;
    return f;
}



int main() {
    char name [6] = "y_.dat";

    double intervall1[2]    ={0.0, 2.0};
    double anfangswert1[2]  ={0.0, 0.2};


    double** erg1_1 = euler(fun1, 0.01,intervall1, anfangswert1 );
    name[1] = '1';
    ergToFile(erg1_1, name, 200);

    double** erg1_2 = euler(fun1, 0.1, intervall1, anfangswert1 );
    name[1] = '2';
    ergToFile(erg1_2, name, 20);

    double** erg1_3 = euler(fun1, 0.5, intervall1, anfangswert1 );
    name[1] = '3';
    ergToFile(erg1_3, name, 4);

    return 0;
}


double teileIntervall(double schrittweite, double intervall[]) //Gibt an in wieviel Stücke das Intervall geteilt wird
{
    double n;
    n = (intervall[1] -intervall[0])/schrittweite;
    return n;
}

double** euler(double (*funktion)(double, double),double schrittweite, double intervall[], double anfangswert[])
{

    int  n = (int)teileIntervall(schrittweite, intervall);
    //Lösungsmatrix erstellen
    double** erg = malloc(n * sizeof(double*));

    for(int i = 0; i < n; i++)
    {
        erg[i] = calloc(2,sizeof(double));
    }

    //Euler Methode

        erg[0][0] = anfangswert[0];
        erg[0][1] = anfangswert[1];

    for(int i = 1; i < n; i++)
    {

        erg[i][0] = anfangswert[0] + (i) * schrittweite;  //t-Wert berechnen und in Lösungsmatrix speichern
        erg[i][1] = erg[i-1][1] + schrittweite * funktion(erg[i-1][0], erg[i-1][1]);   //y(t)-Wert berechnen
    }


    return erg;
}

int ergToFile(double** erg, char name[], int anzahlzeilen)  //Schreibt Lösungsmatrix in FILE;
{
    int i;
    FILE* file_ptr = fopen(name, "w");
    if(file_ptr == NULL)
    {
      fprintf(stderr, "DATEI KONNTE NICHT ERSTELLT WERDEN!\n");
      return(EXIT_FAILURE);
    }

    for(i = 0; i < anzahlzeilen; i++){
          fprintf(file_ptr,"%f  ", erg[i][0]);
          fprintf(file_ptr,"%f\n", erg[i][1]);
        }
    fclose(file_ptr);
    return 0;
}
