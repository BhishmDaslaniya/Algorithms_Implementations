#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//O(mn)
void naive_algo(string s,string p){
    vector<ll> m;
    ll ls = s.length();
    ll lp = p.length();
    for(ll i = 0 ; i <= ls-lp ; i++ ){
        ll valid = true;
        for(ll j = 0 ; j <= lp-1 ;j++){
            if(p[j] != '*' && p[j]!= s[i+j]){
                valid = false;
            }
        }
        if(valid){
            m.push_back(i);
        }
    }
    cout<<"All matching positions are:";
    for(ll i = 0 ; i < m.size();i++){
        cout<<m[i]<<",";
    }
    cout<<endl;
}

int main(){
    string s,p;
    cout<<"Give String :";
    cin>>s;
    cout<<"Give pattern with wildcard * : ";
    cin>>p;
    naive_algo(s,p); 
}