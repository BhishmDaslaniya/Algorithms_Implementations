#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll BNMCOEF(ll n,ll k){
    ll C[n+1][k+1] ;
    memset(C,0,sizeof(C));
    for(ll i = 0 ; i <= n ; i++){
        for(ll j = 0 ; j <= min(i,k);j++){
            if(j==0 || j==i){
                C[i][j] = 1;
            }else{
                C[i][j] = C[i-1][j-1]+C[i-1][j];
            }
        }
    }
    
    cout<<"---------------------------------------"<<endl;

    for(ll i = 0 ; i <= n ; i++){
        for(ll j = 0; j <= k ; j++ ){
            cout<<C[i][j]<<" ";
        }
        cout<<"\n";
    }
    return C[n][k];
}

int main(){
    ll n,k;
    cout<<"Enter n and k for compute nCk : ";
    cin>>n>>k;
    ll ans = BNMCOEF(n,k);
    cout<<"value of "<<n<<"C"<<k<<" : "<< ans<<endl;
    return 0;
}