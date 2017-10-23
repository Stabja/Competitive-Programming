#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 4

int min(int a, int b)
{ return (a < b)? a: b; }

int min(int a, int b, int c)
{ return min(min(a, b), c);}

int max(int a, int b)
{ return (a > b)? a: b; }

void diagonalOrder(int matrix[][COL])
{
    for (int line=1; line<=(ROW + COL -1); line++)
    {
        int start_col =  max(0, line-ROW);
        int count = min(line, (COL-start_col), ROW);
        for (int j=0; j<count; j++){
            printf("%5d ", matrix[start_col+j][min(ROW, line)-j-1]);
        }
        printf("\n");
    }
}

void diagonalOrder2(int matrix[][COL])
{
    for (int line=1; line<=(ROW + COL -1); line++)
    {
        int start_col =  max(0, line-ROW);
        int count = min(line, (COL-start_col), ROW);
        for (int j=0; j<count; j++){
            printf("%5d ", matrix[start_col+j][COL-1-(min(ROW, line)-j-1)]);
        }
        printf("\n");
    }
}

void printMatrix(int matrix[ROW][COL])
{
    for (int i=0; i< ROW; i++)
    {
        for (int j=0; j<COL; j++)
            printf("%5d ", matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int M[4][4] = {{ 1,  2,  3,  4},
                   { 5,  6,  7,  8},
                   { 9, 10, 11, 12},
                   {13, 14, 15, 16},
                  };

    //printMatrix(M);
    diagonalOrder(M);
    diagonalOrder2(M);
    return 0;
}
