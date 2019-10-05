#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void permutations(string s, ll i, ll n){
    if(i == n-1){
        cout<<s<<",";
        return;
    }
    for(ll j = i ; j < n ;j++){
        swap(s[i],s[j]);
        permutations(s,i+1,n);
        swap(s[i],s[j]);
    }
}

int main(){
    string s;
    cout<<"Give String : ";
    cin>>s;
    permutations(s,0,s.length());
    return 0;
}