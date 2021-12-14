#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "mem.h"
#include "backtrack.h"


/*
    El problema de las N-Reinas consiste en colocar n reinas en un tablero de n x n de tal manera que ninguna 
    reina pueda atacar a otra, es decir, no pueden haber 2 reinas en la misma columna, fila o diagonal.
*/

/*
    Para este problema vamos a representar a cada reina en el tablero con el número 1.
*/

int main()
{
    // Definimos el n con el que trabajaremos.
    int n = 7;

    // Definimos la cantidad de reinas que ya hemos posicionado. Inicialemente es cero.
    int* placed_queens = calloc(1, sizeof(int));
    *placed_queens = 0;

    // Creamos el tablero de n x n.
    int** board = calloc(n, sizeof(int*));
    for (int x=0; x<n; x++)
    {
        board[x] = calloc(n, sizeof(int));
    }

    // Aplicamos backtracking para poder resolver el problema.
    bool solved = solve_NQueens(n, board, placed_queens);
    if (solved)
    {
        // Si es que conseguimos una solución, la imprimimos en consola.
        printf("\nLA SOLUCIÓN ENCONTRADA PARA N = %i ES LA SIGUIENTE\n", *placed_queens);
        print_board(board, n);
    }
    else
    {
        printf("No se encontró solución.");
    }

    // Liberamos memoria utilizada.
    free_board(board, n);
    free(placed_queens);
    return 1;
}