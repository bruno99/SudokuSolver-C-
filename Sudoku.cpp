/*
 * BRUNO URBAN ALFARO
 * En este programa uso el metodo backtracking.
 * Consiste en probar numeros y volver sobre tus pasos en caso de error.
 * Asi sucesivamente hasta llegar a la solucion en caso de haber una
 * */


#include <iostream>
using namespace std;

//Uso N en lugar de 9 para que en caso de querer resolver
//Sudokus de otros tamaños poder hacerlo con un solo cambio aqui
#define N 9


//Encuentra un hueco vacío (asignado a 0)
bool EncuentraLocalizacion(int tablero[N][N],
                            int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (tablero[row][col] == 0)
                return true;
    return false;
}

//Comprueba si algun numero de la fila coincide con el metido
bool PruebaFila(int tablero[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (tablero[row][col] == num)
            return true;
    return false;
}

//Comprueba si algun numero de la columna coincide con el metido
bool PruebaColumna(int tablero[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (tablero[row][col] == num)
            return true;
    return false;
}

//Comprueba si algun numero de el bloque de 3x3 coincide con el metido
bool PruebaBloque(int tablero[N][N], int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (tablero[row + boxStartRow]
                    [col + boxStartCol] == num)
                return true;
    return false;
}

//Esta funcion nos dice si se puede colocar el numero en el hueco que intentamos
bool isSafe(int tablero[N][N], int row,
                   int col, int num)
{
    /* Check if 'num' is not already placed in
    current row, current column and current 3x3 box */
    return !PruebaFila(tablero, row, num) &&
           !PruebaColumna(tablero, col, num) &&
           !PruebaBloque(tablero, row - row % 3 ,
                      col - col % 3, num) &&
            tablero[row][col] == 0;
}

void print(int tablero[N][N])
{
    for (int row = 0; row < N; row++)
    {
    for (int col = 0; col < N; col++)
            cout << tablero[row][col] << " ";
        cout << endl;
    }
}
bool SolucionSudoku(int tablero[N][N])
{
    int row, col;


    if (!EncuentraLocalizacion(tablero, row, col))
    return true; // Sudoku terminado


    for (int num = 1; num <= 9; num++)
    {

        if (isSafe(tablero, row, col, num))
        {
           //prueba un numero
            tablero[row][col] = num;

            //Numero correcto
            if (SolucionSudoku(tablero))
                return true;

            //Numero no correcto
            tablero[row][col] = 0;
        }
    }
    return false;
}



int main()
{

    int tablero[N][N] = {{0, 0, 8, 4, 9, 0, 6, 0, 0},
                      {6, 0, 4, 7, 0, 3, 2, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 7},
                      {0, 8, 0, 2, 0, 0, 1, 0, 0},
                      {0, 0, 1, 0, 0, 8, 5, 7, 0},
                      {7, 0, 6, 5, 0, 4, 3, 0, 9},
                      {8, 6, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 0, 0, 2, 0, 0, 5, 8},
                      {0, 4, 0, 0, 5, 0, 0, 0, 0}};
    if (SolucionSudoku(tablero) == true)
        print(tablero);
    else
        cout << "No existe solucion";

    return 0;
}
