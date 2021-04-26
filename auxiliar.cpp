# include "auxiliar.h"

// Encuentra el tamaño de un array
int lengthof(char *c)
{
    unsigned short int counter = 0;
    for(unsigned short int i = 0; c[i] != '\0'; i++){
        counter += 1;
    }
    return counter;
}

// Encuentra cuantos digitos tiene un numero
int digits(int number)
{
    unsigned short int counter = 0;
    while(number != 0) {
        number /= 10;
        counter++;
    }
    return counter;
}

int ** matriz(int *m, int elementos)
{
    int n = sqrt(elementos);
    int **mat = new int * [n];

    for(int i=0; i<n; i++) *(mat+i) = new int [n];

    for(int f=0;f<n;f++){
        for(int c=0; c<n; c++) mat[f][c]=m[c+f*n];
    }

    return mat;
}
