#include<bits/stdc++.h>
using namespace std;
int c = 0;

int gcd(int a, int b){
    c++;
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

int main(){
    for(int i = 0 ; i < 2 ; i++){
        int a,b;
        cout<<"Enter two numbers : "<<endl;
        cin>>a>>b;
        int ans = gcd(a,b);
        cout<<"Answer is     : "<<ans<<endl;
        cout<<"Total steps   : "<<c<<endl;
        cout<<"complexity is : "<<log2(min(a,b))<<endl;
    }
    return 0;
}