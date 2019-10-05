#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n;
    cout<<"Enter number of vertices : ";
    cin>>n;
    ll mat[n][n];
    memset(mat,0,sizeof(mat));
    ll e;
    cout<<"Enter number of edges : ";
    cin>>e;
    cout<<"Enter the values for edges with weight:(start from 1...)\n";
    cout<<"Format of entering values (start weight end):::\n";
    ll x,y,z;
    for(ll i = 0 ; i < e ; i++){
        cin>>x>>y>>z;
        mat[x-1][z-1] = y;
        mat[z-1][x-1] = y;
    }
    
    ll  selected[n] ;
    memset(selected,false,sizeof(selected));
    ll edge_coverd = 0;
    selected[0] = true;
    ll min_weight  = 0;
    cout<<"selected edges are: \n";
    cout<<"Edge\t:\tweight"<<endl;
    while(edge_coverd!= n-1){
        ll m = INT_MAX;
        ll row = 0;
        ll column = 0;
        for(ll i = 0 ; i < n ; i++){
            if(selected[i]){
                for(ll j = 0 ; j < n ; j++){
                    //not selected and there is an edge!
                    if(!selected[j] && mat[i][j]){
                        if(m > mat[i][j]){
                            m = mat[i][j];
                            row = i;
                            column = j;
                        }
                    }
                }
            }
        }
        cout<<row+1<<" - "<<column+1<< "   : \t"<< mat[row][column]<<endl;
        min_weight+=mat[row][column];
        selected[column] = true;
        edge_coverd++;
    }

    cout<<"MST weight : " <<min_weight<<endl;
}