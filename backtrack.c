#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "mem.h"

/*
    El problema de las N-Reinas consiste en colocar n reinas en un tablero de n x n de tal manera que ninguna 
    reina pueda atacar a otra, es decir, no pueden haber 2 reinas en la misma columna, fila o diagonal.
*/

/* Función para conseguir las diagonales. */
int** get_diagonals(int x, int y, int N)
{
    // Creamos array para guardar las diagonales.
    int** diagonals = calloc(2*N-2, sizeof(int*));
    for (int i=0; i<2*N-2; i++)
    {
        diagonals[i] = calloc(2, sizeof(int));
        diagonals[i][0] = -1;
        diagonals[i][1] = -1;
    }

    int added_diagonals = 0;
    // Arriba a la izquierda.
    for (int i=x-1, j=y-1; i>=0 && j>=0; i--, j--)
    {
        diagonals[added_diagonals][0] = i;
        diagonals[added_diagonals][1] =  j;
        added_diagonals += 1;
    }
    // Abajo a la izquierda.
    for (int i=x+1, j=y-1; i<N && j>=0; i++, j--)
    {
        diagonals[added_diagonals][0] = i;
        diagonals[added_diagonals][1] =  j;
        added_diagonals += 1;
    }
    // Arriba a la derecha.
    for (int i=x-1, j=y+1; i>=0 && j<N; i--, j++)
    {
        diagonals[added_diagonals][0] = i;
        diagonals[added_diagonals][1] =  j;
        added_diagonals += 1;
    }
    // Abajo a la derecha.
    for (int i=x+1, j=y+1; i<N && j<N; i++, j++)
    {
        diagonals[added_diagonals][0] = i;
        diagonals[added_diagonals][1] =  j;
        added_diagonals += 1;
    }
    return diagonals;
}


/*
    Función para ver si una reina ataca al resto. Recibe como parámetros la posición, x e y, a colocar la reina, el número N del problema y el tablero.
*/
bool queen_attacks(int x, int y, int N, int** board)
{
    /* Revisamos la fila de la reina en busca de otra reina */
    for (int i=y+1; i<N; i++)
    {
        if (board[x][i] == 1)
        {
            return true;
        }
    }

    for (int i=y-1; i>=0; i--)
    {
        if (board[x][i] == 1)
        {
            return true;
        }
    }
    

    /* Revisamos las diagonales de la reina en busca de otra reina */
    int** diagonals = get_diagonals(x, y, N);
    for (int i=0; i<(2*N-2); i++)
    {
        int diag_x = diagonals[i][0];
        int diag_y = diagonals[i][1];

        if ( (diag_x != -1 && diag_y != -1) && board[diag_x][diag_y] == 1)
        {
            free_diagonal(diagonals, N);
            return true;
        }
    }
    free_diagonal(diagonals, N);
    return false;
}


/* Función de backtrack */
bool solve_NQueens(int N, int** board, int* placed_queens)
{
    // Si es que la cantidad de reinas colocadas es N, entonces resolvimos el problema.
    if (*placed_queens == N)
    {
        return true;
    }

    // Recorremos todas las filas donde la reina podría ir ubicada.
    for (int row=0; row<N; row++)
    {
        // Vemos la reina atacaría a otra en esta posición.
        if (queen_attacks(row, *placed_queens, N, board) == false)
        {
            // Realizamos asignación de posición de la reina.
            board[row][*placed_queens] = 1;
            *placed_queens += 1;
            // Intentamos resolver el problema con esta asignación.
            if (solve_NQueens(N, board, placed_queens))
            {
                return true;
            }
            *placed_queens -= 1;
            board[row][*placed_queens] = 0;
        }
    }
    return false;
        

    return false;
}

