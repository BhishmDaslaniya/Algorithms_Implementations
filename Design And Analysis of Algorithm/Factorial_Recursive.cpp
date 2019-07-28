#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int c = 0;
ll factorial(int n)
{
    if (n == 0)
        return 1;
    else
    {
        c++;
        return n * factorial(n - 1);
    }
}

int main()
{
    int inputArr[5] = {5, 10, 15, 20, 25};
    cout << "----------------------------------------" << endl;
    for(int x = 0 ; x < 5 ; x++){
        c = 0;
        int input = inputArr[x];
        ll ans = factorial(input);
        cout << "Input is   : " << input << endl;
        cout << "Ans is     : " << ans << endl;
        cout << "Total steps: " << c << endl;
        cout << "----------------------------------------" << endl;
    }
}
