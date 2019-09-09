#include <bits/stdc++.h>
using namespace std;
int c = 0;

int linearSearch(int arr[],int sz,int ele){
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == ele)
        {
            cout << "Found Index is : " << i + 1 << endl;
            break;
        }
        c++;
    }
    if(c == sz){
        return 0;
    }else{
        return 1;
    }
}

int main()
{
    int sz;
    cout << "Size : ";
    cin >> sz;
    int arr[sz];
    cout << "Input array : ";
    for (int i = 0; i < sz; i++){
        cin >> arr[i];
    }
    cout << "Element for found :";
    int ele;
    cin >> ele;
    if(linearSearch(arr,sz,ele)){
        cout << "Total steps: " << c+1 << endl;
    }else{
    cout<<"Not Found"<<endl;
    }
}
