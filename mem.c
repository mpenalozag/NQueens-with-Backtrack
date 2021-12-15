#include <stdlib.h>
#include <stdio.h>

/* Función para liberar memoria usada del tablero */
void free_board(int** board, int n)
{
    for (int i=0; i<n; i++)
    {
        free(board[i]);
    }
    free(board);
}

/* Función para liberar una diagonal del tablero */
void free_diagonal(int** diagonal, int N)
{
    for (int i=0; i<2*N-3; i++)
    {
        free(diagonal[i]);
    }
    free(diagonal);
}

/* Función para printear el tablero */
void print_board(int** board, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int i=0; i<n; i++)
        {
            printf("  - ");
        }
        printf("\n");
        printf("|");

        for (int j=0; j<n; j++)
        {
            if (board[i][j] == 1)
            {
                printf(" Q |");
            }
            else
            {
                printf("   |");
            }
        }
        printf("\n");
        
    }
    for (int i=0; i<n; i++)
    {
        printf("  - ");
    }
    printf("\n");
}