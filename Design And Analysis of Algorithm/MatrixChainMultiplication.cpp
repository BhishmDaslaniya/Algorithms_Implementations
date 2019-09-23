#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Source : https://www.geeksforgeeks.org/printing-brackets-matrix-chain-multiplication-problem/

void printParenthesis(int i, int j, int n, int *bracket, char &name){ 
    if (i == j){ 
        cout << name++; 
        return; 
    } 
    cout << "("; 
    printParenthesis(i, *((bracket+i*n)+j), n, bracket, name); 
    printParenthesis(*((bracket+i*n)+j) + 1, j, n, bracket, name); 
    cout << ")"; 
} 

ll MCM(ll p[] , ll n){
    int m[n][n]; 
    int bracket[n][n]; 
    for (int i=1; i<n; i++) 
        m[i][i] = 0; 

    for (int L=2; L<n; L++){ 
        for (int i=1; i<n-L+1; i++){ 
            int j = i+L-1; 
            m[i][j] = INT_MAX; 
            for (int k=i; k<=j-1; k++){ 
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j]){ 
                    m[i][j] = q;  
                    bracket[i][j] = k; 
                } 
            } 
        } 
    } 
    char name = 'A'; 
  
    cout << "Optimal Parenthesization is : "; 
    printParenthesis(1, n-1, n, (int *)bracket, name);
    cout<<endl; 
    return m[1][n-1];
}

int main(){
    cout<<"Enter number of matrices : ";
    ll n;
    cin>>n;
    ll dim[n+1];
    cout<<"Enter values of (n+1) dimentions for n matrices : "<<endl;
    for(ll i = 0 ; i <= n ; i++){
        cin>>dim[i];
    }
    cout<<"Minimum number of multiplications : "<<MCM(dim,n+1)<<endl;
}