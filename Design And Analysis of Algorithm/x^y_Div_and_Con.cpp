#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long int ll;
int c = 0;
ld power(ld x, ll y){
    ld t;
    c++;
    if (y == 0)
    {
        return 1;
    }
    t = power(x, y / 2);
    if(y%2==0){
        return (t * t);
    }else{
        if (y > 0)
            return (x * t * t);
        else
            return ((t * t) / x);
    }
}

int main(){
    ld x;
    ll y;
    cout<<"Enter x and y for x^y : ";
    cin>>x>>y;
    cout<<"Answer is : "<<power(x,y)<<endl;
    cout<<"Number of multiplication is : "<<c<<endl;
    return 0;
}