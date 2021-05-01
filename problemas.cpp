#include "problemas.h"
/* Ejercicio 1 de arduino:
 * https://www.tinkercad.com/things/cFxlIevPU6A-incredible-amberis/editel?sharecode=LwIOqwhAILjA2FEUW016cNKo-t8lG6xXYDfK5i2xgao */

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
    for(short int i = (size_c - 1), j = 1; i >= 0 ; i--, j *= 10) {
        number = (c[i] - 48) * j;
        result += number;
    }
    return result;
}

/* Haga una función que reciba un numero entero (int) y lo convierta a cadena de caracteres. */
void problema5(int num, char *c)
{
    unsigned short int digit, digits_number = digitsof(num); // Digitos del numero

    // Ciclo que recorre el array de atras para adelante y va dividiendo el numero de igual forma
    for(short int i = (digits_number - 1); i >= 0; i--) {
        digit = num % 10;
        digit += 48;
        c[i] = char(digit);
        num /= 10;
    }
    cout << c << endl;
}

/* Escriba un programa que reciba una cadena de caracteres y cambie las letras minúsculas por mayúsculas,
 * los demás caracteres no deben ser alterados. */
char * problema6(char *c)
{
    char letter; // Variable que contendra cada posición del array
    unsigned short int size_c = lengthof(c); // Tamaño del array

    // Ciclo para recorrer el array
    for(unsigned short int i = 0; i < size_c; i++) {
        // Condicional para ver si es una letra minuscula
        if(c[i] > 96 && c[i] < 123) {
            letter = char(c[i] - 32);
            c[i] = letter;
        }
    }
    return c;
}

/* Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos. */
void problema7(char *c)
{
    cout << "Original: " << c << ". ";
    unsigned short int counter = 0, size_c = lengthof(c); // Tamoño del array
    char new_array[size_c], *new_c = array(new_array, size_c); // Variable para hacer el nuevo array

    // Ciclo para recorrer el array
    for(unsigned short int i = 0; i < size_c; i++) {
        if(true == in(c[i], new_c, size_c)) {
            new_c[counter] = c[i];
            counter ++;
        }
    }
    cout << "Sin repetir: " << new_c << endl;
}

/* Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres,
 * generando una cadena que no tiene números y otra con los números que había en la cadena original. */
void problema8(char *c1, char *c2)
{
}

/* Escribir un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa
 * debe separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse
 * dividir exactamente en números de n cifras se colocan ceros a la izquierda del primer número. */
long long int problema9(char *c, long long int n)
{
    unsigned long long int number, final_number = 0, result = 0;
    unsigned short int size_c = lengthof(c); // Tamaño del array

    // Ciclo para recorrer el array y organizar las grupos de numeros
    for(short int i = (size_c - 1), j = 1, k = 1; i >= 0; i--, j++) {
        if(j <= n) {
            number = (c[i] - 48) * k;
            final_number += number;
            k *= 10; // Da la posicion del numero
        }
        if(j == n || i == 0) {
            result += final_number;
            final_number = 0;
            j = 0;
            k = 1;
        }
    }
    return result;
}

/* Escribir un programa que permita convertir un número en el sistema romano al sistema arábigo usado actualmente. */
long long int problema10(char *c)
{
    char letter, next_letter, roman_system[7] = { 'I','V','X','L','C','D','M' }; // Array como los numeros romanos
    int arabic_system[7] = { 1,5,10,50,100,500,1000 }; // Valor de cada numero romano segun su posicion
    unsigned short int size_c = lengthof(c); // Tamaño del array
    unsigned short int position, next_position;
    unsigned int result;

    // Ciclo para recorrer el array ingresado
    for(unsigned short int i = 1; i < size_c; i++) {
        letter = c[i - 1]; // Letra
        next_letter = c[i]; // Letra siguiente
        //Ciclo para recorrer el array de numeros romanos y el array de numeros arabigos
        for(unsigned short int j = 0; j < 7; j++) {
            if(letter == roman_system[j]) { position = j; } // Numero romano
            if(next_letter == roman_system[j]) { next_position = j; } // Numero siguiente al anterior
        }
        if(i == 1) { result = arabic_system[position]; } // Primer numero romano
        result += arabic_system[next_position]; // Suma normal

        // Si el primer numero es menor que el otro aca se realiza la resta
        if(arabic_system[position] < arabic_system[next_position]) {
            result -= (arabic_system[position] + arabic_system[position]);
        }
    }
    return result;
}
/* link tinkercad
 * "https://www.tinkercad.com/things/kKmpHaz4rTJ-fantastic-duup-jaban/editel?sharecode=0iN4drStrJk9Et1dyJA9C_ZTASwVC_QjyHJBGHHJBqM" */


/* Escriba un programa que permita manejar las reservas de asientos en una sala de cine, los asientos de
 * la sala de cine están organizados en 15 filas con 20 asientos cada una. El programa debe mostrar una representación
 * de la sala que indique que asientos están disponibles y cuales se encuentran reservados. Además debe permitir
 * realizar reservas o cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20). */
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

/* Elabore y pruebe una función que reciba un puntero a la matriz de enteros como argumento y que retorne el número
 * de estrellas encontradas en la imagen. Ignore las posibles estrellas que puedan existir en los bordes de la matriz. */
int problema13(int *mat)
{
    unsigned int stars = 0, matrix[6][8];
    float result;

    // Ciclo para hacer la matriz
    for(unsigned short int row = 0, i = 0; row < 6; row++) {
        for(unsigned short int column = 0; column < 8; column++, i++) {
            matrix[row][column] = *(mat + i);
        }
    }

    // Ciclo para recorrer la matriz
    for(unsigned short int row = 1; row < 5; row++) {
        for(unsigned short int column = 1; column < 7; column++) {
            result = (matrix[row][column] + matrix[row][column - 1] + matrix[row][column + 1] + matrix[row - 1][column] + matrix[row + 1][column]) / float(5);
            if(result > 6) { stars++; }
        }
    }
    return stars;
}

/* Elabore un programa que llene una matriz 5x5 con los números del 1 al 25 y la imprima, luego
 * imprima la matriz rotada 90, 180 y 270 grados. */
void problema14()
{
    int number = 0, matrix[5][5];
    cout << "Matriz original" << endl;

    // Ciclo para formar la matriz
    for(unsigned short int row = 0; row < 5; row++) {
        for(unsigned short int column = 0; column < 5; column++) {
            number ++;
            matrix[row][column] = number;
            cout << number << "\t";
        }
        cout << endl << endl << endl;
    }

    // Ciclo para rotar la matriz cada 90 grados
    for(unsigned short int degrees = 90; degrees < 360; degrees += 90) {
        if(degrees == 90) {
            cout << "Matriz rotada 90 grados" << endl;
            // Ciclo que imprime la matriz en 90 grados
            for(unsigned short int column = 0; column < 5; column++) {
                for(short int row = 4; row >= 0; row--) { cout << matrix[row][column] << "\t"; }
                cout << endl << endl << endl;
            }
        }
        else if(degrees == 180) {
            cout << "Matriz rotada 180 grados" << endl;
            // Ciclo que imprime la matriz en 180 grados
            for(short int row = 4; row >= 0; row--) {
                for(short int column = 4; column >= 0; column--) { cout << matrix[row][column] << "\t"; }
                cout << endl << endl << endl;
            }
        }
        else {
            cout << "Matriz rotada 270 grados" << endl;
            // Ciclo que imprime la matriz en 270 grados
            for(short int column = 4; column >= 0; column--) {
                for(unsigned short int row = 0; row < 5; row++) { cout << matrix[row][column] << "\t"; }
                cout << endl << endl << endl;
            }
        }
    }
}

/* Elabore un programa que permita hallar la intersección entre un par de rectángulos. */
void problema15(int *dato1, int *dato2)
{
    // Array = { x1,y1,x2,y2 }
    int A[4], B[4]; // Arrays que contendran los rectangulos

    // Ciclo para rellenar el array del rectangulo 1
    for(unsigned short int i = 0, position = 0; position < 4; i++, position++) {
        if(position < 2) { A[position] = *(dato1 + i); }
        else {
            if(position == 2) { A[position] = *(dato1 + i) + A[position - 2]; }
            else { A[position] = A[position - 2] - *(dato1 + i); }
        }
    }
    cout << A << endl;

    // Ciclo para rellenar el array del rectangulo 2
    for(unsigned short int i = 0, position = 0; position < 4; i++, position++) {
        if(position < 2) { B[position] = *(dato2 + i); }
        else {
            if(position == 2) { B[position] = *(dato2 + i) + B[position - 2]; }
            else { B[position] = B[position - 2] - *(dato2 + i); }
        }
    }

    // Evaluamos x
/*    if(A[0] <= B[0] && B[0] <= A[2]) {
        // Evaluamos y
        if(A[1] <= B[1] && B[1] <= A[3]) {}
        else if(A[1] <= B[3] && B[3] <= A[3]) {}
        else if((A[1] <= B[1] && B[1] <= A[3]) && (A[1] <= B[3] && B[3] <= A[3]))
    }*/
/*    if(A[0] <= B[0] && B[0] <= A[2]) {
        if(A[1] <= B[1] && B[1] <= A[3]) {}
        else if(A[1] <= B[3] && B[3] <= A[3]) {}
        else { cout << "Los rectangulos no se intersectan."; }
    }
    else if(A[0] <= B[2] && B[2] <= A[2]) {
        if(A[1] <= B[1] && B[1] <= A[3]) {}
        else if(A[1] <= B[3] && B[3] <= A[3]) {}
        else { cout << "Los rectangulos no se intersectan."; }
    }
    else if(B[0] <= A[0] && A[0] <= B[2]) {
        if(B[1] <= A[1] && A[1] <= B[3]) {}
        else if(B[1] <= A[3] && A[3] <= B[3]) {}
        else { cout << "Los rectangulos no se intersectan."; }
    }
    else if(B[0] <= A[2] && A[2] <= B[2]) {
        if(B[1] <= A[1] && A[1] <= B[3]) {}
        else if(B[1] <= A[3] && A[3] <= B[3]) {}
        else { cout << "Los rectangulos no se intersectan."; }
    }
    else { cout << "Los rectangulos no se intersectan."; }
*/
}

/* Escriba un programa que reciba un numero n y calcule el número de caminos posibles en una cuadricula de nxn. */
int problema16(int n)
{
    int roads;
    roads = recursiva(0, 0, (n+1), 0);
    return roads;
}

/* Escribir un programa que reciba un número y halle la suma de todos los números amigables menores al número ingresado. */
int problema17(int num)
{
    int sum = 0;
    for(;num > 1; num--) { if(amigable(num)) { sum += num; } }
    return sum;
}

/* Escribir un programa que reciba un número n y halle la enésima permutación lexicográfica de los números entre 0 y 9. */
void problema18(char *p, int n)
{
    char * m;

    // Se asegura de que sea una combinacion lexicografica
    if(n >= 1 && n <= factorial(10)) {
        m = permutaciones((n - 1), 10);
        for(int i = 0; m[i] != '\0'; i++) {
            p[i] = m[i];
        }
        p[10] = '\0';
    }
    else { cout << "El numero de permutaicon no es valido" << endl;}
}
