#include <stdio.h>

int matrix[4][4] = {
    {1, 1, 1, 1},
    {0, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}};

// rotates clockwise
void rotate_matrix()
{
    // flip with the axis running from top left to bottom right
    for (int i = 0; i < 4; i += 1)
    {
        for (int j = 0; j < i; j += 1)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    // flip with axis going down the middle
    for (int y = 0; y < 4; y += 1)
    {
        for (int x = 0; x < 2; x += 1)
        {
            int tmp = matrix[y][x];
            matrix[y][x] = matrix[y][3 - x];
            matrix[y][3 - x] = tmp;
        }
    }
}

// prints the matrix
void print_matrix(int m[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (m[i][j])
                putchar('#');
            else
                putchar(' ');
        }
        puts("");
    }
}

int main()
{
    while (getchar() != EOF)
    {
        print_matrix(matrix);
        rotate_matrix();
    }
}
