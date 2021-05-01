#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <cstdlib>
#include <time.h>
#include <cmath>

int lengthof(char *c);
int digitsof(int number);
char * array(char *c, int size);
bool in(char letter, char *c, int size);
int ** matriz(int *m, int elementos);
int recursiva(int row_n, int column_n, int v, int nodos);
bool amigable(int n);
long long int factorial(int n);
char * permutaciones(int n, int num);
void eliminar(char *p, int n);

#endif // AUXILIAR_H
