#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int c = 0;

int main(){
    int inputArr[5] = {5,10,15,20,25};
    cout<<"----------------------------------------"<<endl; 
    for(int x= 0 ;x < 5 ; x++){
        c = 0;
        int input = inputArr[x];
        ll ans = 1;

        for (int i = 1; i <= input; i++){
            ans *= i;
            c++;
        }
        cout<<"Input is   : "<<input<< endl;
        cout<<"Ans is     : "<<ans<<endl;
        cout<<"Total steps: "<<c<<endl;
        cout << "----------------------------------------" << endl;
    }
    return 0;
}