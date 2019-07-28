#include<bits/stdc++.h>
#include "util_Matrix.cpp"
using namespace std;
int step = 0;

int calculation(int **mat1, int **mat2, int r, int c, int r1, int c1, int r2,int c2)
{
    int ans = 0;
    for (int i = 0, j = 0; j < r2 && i < c1; j++, i++)
    {
        ans += mat1[r][i] * mat2[j][c];
        step += 1;
    }
    return ans;
}

int main(){
    int r1, c1,r2,c2;
    cout << "For matrix1 rows:";
    cin >> r1;
    cout << "For matrix1 columns:";
    cin >> c1;
    cout << "For matrix2 rows:"<<c1<<endl;
    r2 = c1;
    cout << "For matrix2 columns:";
    cin >> c2;

    int** mat1 = newMatrix(r1,c1);
    int **mat2 = newMatrix(r2, c2);
    cout << "Enter values of matrix 1:" << endl;
    scanMatrix(mat1,r1,c1);
    cout << "Enter values of matrix 2:" << endl;
    scanMatrix(mat2,r2,c2);

    int r = r1,c = c2;
    int** ans = newMatrix(r,c);

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)
        {
            ans[i][j] = calculation(mat1, mat2, i, j, r1, c1, r2, c2);
        }
    }

    cout << "Answer:" << endl;
    printMatrix(ans, r, c);
    cout << "Total steps : " << step << endl;

    return 0;
}