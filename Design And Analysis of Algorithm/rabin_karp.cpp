#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int d = 256;

void SearchPattern(string txt, string pat, ll q)  
{  
    ll M =pat.length();
    ll N =txt.length();  
    ll p = 0; // hash value for pattern  
    ll t = 0; // hash value for txt  
    ll h = 1;  
  
    // The value of h would be "pow(d, M-1)%q"  
    for (ll i = 0; i < M - 1; i++)  
        h = (h * d) % q;  
  
    // Calculate the hash value of pattern and first  
    // window of text  
    for (ll i = 0; i < M; i++){  
        p = (d * p + pat[i]) % q;  
        t = (d * t + txt[i]) % q;  
    }
  
    // Slide the pattern over text one by one  
    for (ll i = 0; i <= N - M; i++){  
        if ( p == t ){  
            ll j;
            for (j = 0; j < M; j++){  
                if (txt[i+j] != pat[j])  
                    break;  
            }  
            if (j == M)  
                cout<<"Pattern found at index "<<i<<endl;  
        }  
  
        if ( i < N-M ){  
            t = (d*(t - txt[i]*h) + txt[i+M])%q;  
            if (t < 0)  
                t = (t + q);  
        }  
    }  
}  

int main(){
    string s,p;
    ll q;
    cout<<"Give String and pattern : ";
    cin>>s>>p;
    cout<<"Enter prime number for hashing : ";
    cin>>q;
    SearchPattern(s,p,q);
}