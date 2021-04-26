#include "problemas.h"

/* Elabore un programa que genere un arreglo de 200 letras mayúsculas aleatorias, imprima este arreglo
 * y luego imprima cuantas veces se repite cada letra en el arreglo. */
void problema2()
{
    unsigned short int number, counter; // Variable numero aleatorio y contador
    unsigned char array_letters[200]; // Lista para contener las letras
    srand(time(NULL));
    cout << "{";

    // Ciclo para rellenar la lista (array_letters)
    for(unsigned short int i = 0; i < 200; i++){
        number = rand() % (90 - 65 +1) + 65;
        array_letters[i] = char(number);
        if(i != (200 - 1)) { cout << array_letters[i] << ", "; }
        else { cout << array_letters[i]; }
    }
    cout << "}" << endl;

    // Ciclo para pasar letra por letra
    for(unsigned short int i = 65; i < 91; i++) {
        cout << char(i) << ": ";
        counter = 0;
        //Ciclo para ver cuantas veces se repite cada digito
        for(unsigned short int j = 0; j< 200; j++) {
            if(char(i) == array_letters[j]) {
                counter += 1;
            }
        }
        cout << counter << endl;
    }
}

/* Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son
 * iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. */
bool problema3(char *c1, char*c2)
{
    bool same = true;
    unsigned short int size_c1 = lengthof(c1); // Tamaño array 1
    unsigned short int size_c2 = lengthof(c2); // Tamaño array 2
    if(size_c1 != size_c2) { same = false; } // Igualamos los tamaños
    //Igualamos cada espacio en el array
    else {
        for(unsigned short int i = 0; i < size_c1; i++) {
            if(c1[i] != c2[i]) { same = false; }
        }
    }
    return same;
}

/* Haga una función que reciba una cadena de caracteres numéricos, la convierta a un número entero
 * y retorne dicho número. */
long long int problema4(char *c)
{
    int result = 0, number;
    unsigned short int size_c = lengthof(c); // Tamaño del array

    // Ciclo para recorrer el array y organizar el int
    for(int i = (size_c - 1), j = 1; i >= 0 ; i--, j *= 10) {
        number = (c[i] - 48) * j;
        result += number;
    }
    return result;
}

void problema5(int num, char *c)
{
    unsigned short int digits_number = digits(num); // Digitos del numero
}

/* Haga una función que reciba un numero entero (int) y lo convierta a cadena de caracteres. */
char * problema6(char *c)
{
}

void problema7(char *c)
{
}

void problema8(char *c1, char *c2)
{
}

long long int problema9(char *c, long long int n)
{
}

long long int problema10(char *c)
{
}

void problema11(char c, char *c2)
{
}

/* Escriba un programa que permita al usuario ingresar una matriz cuadrada, imprima la matriz y verifique
 * si la matriz es un cuadrado mágico. */
bool problema12(int *mat, int elementos)
{
    bool cuadrado=true, logic[10]={0,0,0,0,0,0,0,0,0};
    int **m, e, *fil,*col, diag[2]={0,0};
    m = matriz(mat,elementos);
    e = sqrt(elementos);
    fil = new int [e];
    col = new int [e];
    for(int i=0; i<e; i++){
        fil[i]=0;
        col[i]=0;
    }
for(int f=0; f<e;f++){
        for(int c=0; c<e; c++){
            if(logic[m[f][c]]) cuadrado=false;
            else logic[m[f][c]]=1;
            fil[f]+=m[f][c];
            col[c]+=m[f][c];
            if(f==c) diag[0]+=m[f][c];
            if(f==(e-1)-c) diag[1]+=m[f][c];
        }
    }
for(int i=1;i<e;i++){
        if(fil[i]!=fil[i-1] || col[i]!=col[i-1]) cuadrado=false;
    }
    if(diag[0]!=diag[1] || fil[0]!=col[0] || col[0]!=diag[0] || fil[0]!=diag[0]) cuadrado=false;
    delete fil;
    delete col;
    delete []m;
    return cuadrado;
}

int problema13(int *mat)
{

}

void problema14()
{

}

void problema15(int *dato1, int *dato2, int *cruce)
{

}

int problema16(int n)
{

}

int problema17(int num)
{

}

void problema18(char *p, int n)
{

}
