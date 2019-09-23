#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll KnapsackDP(vector < pair < ll,ll > > v , ll W , ll n){
    ll value[n+1][W+1];

    for(ll i = 0 ; i <= n ; i++){
        for(ll j = 0 ; j<= W;j++){
            if(i == 0 || j==0){
                value[i][j] = 0;
            }else if( v[i-1].second <= j ){
                value[i][j] = max(v[i-1].first + value[i-1][j-(v[i-1].second)], value[i-1][j] );
            }else{
                value[i][j] = value[i-1][j];
            }
        }
    }
    return value[n][W];
}

int main(){
    ll n;
    cout<<"Enter total number of items : ";
    cin>>n;
    ll val[n],wt[n];
    vector < pair < ll , ll > > v;
    cout<<"------------------------------------------\n";
    ll tp,tw;
    for(ll i =  0 ; i < n ; i++){
        cout<<"Enter Profit and weight for item "<<i+1<<" :";
        cin>>tp>>tw;
        v.push_back(make_pair(tp,tw));
    }
    ll W;
    cout<<"Enter capacity of Knapsack : ";
    cin>>W;
    cout<<"Max Profit : "<<KnapsackDP(v,W,n);
}