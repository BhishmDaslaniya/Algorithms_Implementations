#include<bits/stdc++.h>
#include "util_Matrix.cpp"
using namespace std;

int step = 0;

int main(){
    int r,c;
    cout<<"Enter number of rows:";
    cin>>r;
    cout << "Enter number of columns:";
    cin>>c;

    int** mat1 = newMatrix(r,c);
    int** mat2 = newMatrix(r, c);
    cout<<"Enter values of matrix 1:"<<endl;
    scanMatrix(mat1,r,c);
    cout << "Enter values of matrix 2:" << endl;
    scanMatrix(mat2, r, c);
    int** ans = newMatrix(r,c);
    for(int i = 0 ; i < r ;i++){
        for(int j = 0 ; j < c;j++){
            step += 1;
            ans[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    cout<<"Answer:"<<endl;
    printMatrix(ans,r,c);
    cout<<"Total steps : "<<step<<endl;
    return 0;
}