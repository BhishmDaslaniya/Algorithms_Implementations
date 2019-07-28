#include<bits/stdc++.h>
using namespace std;

int **newMatrix(int r, int c)
{
    int **mat = new int *[r];
    for (int i = 0; i < r; i++)
    {
        mat[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            mat[i][j] = 0;
        }
    }
    return mat;
}

void scanMatrix(int **mat, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int **mat, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
