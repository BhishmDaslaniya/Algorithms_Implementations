#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll amt;
    cout<<"Enter total amount : ";
    cin>>amt;
    ll n;
    cout<<"Enter total number of coins available : ";
    cin>>n;
    cout<<"Enter coins values : ";
    ll coins[n];
    for(ll i=  0 ; i < n ; i++){
        cin>>coins[i];
    }

    ll table[n][amt+1];

    memset(table,-1,sizeof(table));

    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < amt+1; j++){
            if(j == 0){
                table[i][j]=0;
            }else if(coins[i]==1){
                table[i][j]=j;
            }else if(coins[i]==j){
                table[i][j]=1;
            }else if(i==0 && j%coins[i]==0){
                table[i][j]=j/coins[i];
            }else if(i!=0){
                if (j - coins[i] >= 0 && table[i][j-coins[i]] != -1) 
                {
                    table[i][j] = min(table[i][j-coins[i]] + 1,table[i-1][j]) ;
                    if (table[i][j] == -1 && table[i][j - coins[i]] + 1 != -1){
                        table[i][j] = table[i][j - coins[i]] + 1;
                    }
                }else{
                    table[i][j] = table[i-1][j];
                }
            }
        }   
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < amt + 1; j++)
        {
            printf("%3ld",table[i][j]);
        }
        cout<<endl;
    }
    vector<ll> SelectedCoins;
    ll totalCoins = table[n-1][amt];
    cout << "Total number of coins : " << table[n - 1][amt] << endl;
    ll index = amt;
    for(ll i = n-1 ; i>=0;i--){
        while(table[i][index]==table[i-1][index]){
            i--;
        }
        if(table[i][index] != 0)
            SelectedCoins.push_back(coins[i]);
        index = index-coins[i];
    }
    cout<<"Coins are : ";
    for(ll i= 0 ; i < SelectedCoins.size();i++){
        cout<<SelectedCoins[i]<<" ";
    }
}