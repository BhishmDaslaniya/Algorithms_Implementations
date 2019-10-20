#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector< ll > vi;
typedef pair< ll, ll > pi;
typedef vector< pi > vip;
typedef set< ll > si;
typedef map< string , ll > msi;
#define rep(i ,a, b) for(ll i = a ; i < b ;i++)
#define rev(i ,b) for(ll i = b ; i >= 0 ;i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mem(n,m) memset(n,m,sizeof(n))
const int mod = 1e9+7 ;

ll DoMod(ll n){
    return ((n%mod)+mod)%mod;
}

bool SortBySecAsc(const pi &a, const pi &b){ 
    return (a.second < b.second); 
} 

bool SortByFirstDesc(const pi &a, const pi &b){ 
    return (a.first > b.first); 
}

bool SortBySecDesc(const pi &a,const pi &b){ 
    return (a.second > b.second); 
} 

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        
    }
}