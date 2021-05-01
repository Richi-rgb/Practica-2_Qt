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
int digitsof(int number)
{
    unsigned short int counter = 0;
    while(number != 0) {
        number /= 10;
        counter++;
    }
    return counter;
}

// Pone un array con caracteres 0 o vacio
char * array(char *c, int size)
{
    for(unsigned short int i = 0; i < size; i++) {
        if(c[i] != 0){
            c[i] = 0;
        }
    }
    return c;
}

// Revisa si un caracter esta en un array
bool in(char letter, char *c, int size)
{
    bool affirmation = true;
    for(unsigned short int i = 0; i < size; i++) {
        if(letter == c[i]) {
            affirmation = false;
            break;
        }
    }
    return affirmation;
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

int recursiva(int row_n, int column_n, int v, int nodos)
{
    bool roads[2]; // roads[0] si hay mov a la derecha y roads[1] si hay mov hacia abajo
    roads[0] = (column_n < v);
    roads[1] = (row_n < v);
    if(row_n == (v - 1) && column_n == (v - 1)) { nodos++; }
    if(roads[0]) { nodos = recursiva(row_n, (column_n + 1), v, nodos); }
    if(roads[1]) { nodos = recursiva((row_n +1), column_n, v, nodos); }
    return nodos;
}

bool amigable(int n)
{
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= (n / 2); i++) { if((n % i) == 0) { sum1 +=i; } }
    for(int i = 1; i <= (sum1 / 2); i++) { if((sum1 % i) == 0) { sum2 +=i; } }
    return (sum2 == n && n != sum1);
}

// Encuentra el facturial de un numero
long long int factorial(int n)
{
    long long int fact = 1;
    // Ciclo que encuentra el factorial de un numero n
    for(;n > 1; n--) {
        fact *= n;
    }
    return fact;
}

char *permutaciones(int n, int num)
{
    int grupo;
    char combina[] = "0123456789"; // Grupos
    static char permuta[11];
    permuta[10] = '\0';

    // Ciclo que encuentra el numero indicado en cada posicion
    for(;num >= 1; num--) {
        grupo = n / factorial(num - 1);
        permuta[10 - num] = combina[grupo];
        eliminar(combina, grupo);
        n %= factorial(num - 1);
    }
    return permuta;
}

// Elimina caracterres de un array
void eliminar(char *p, int n)
{
    for(int i = n; p[i] != '\0'; i++) p[i] = p[i + 1];
}

