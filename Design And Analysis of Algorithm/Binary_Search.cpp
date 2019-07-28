#include <bits/stdc++.h>
using namespace std;
int c = 0;
int BinarySearch(int f, int l, int e, int arr[])
{
    c++;
    if (l >= f)
    {
        int mid = f + (l - f) / 2;
        if (arr[mid] == e)
        {
            return mid;
        }
        else if (arr[mid] < e)
        {
            f = mid + 1;
            return BinarySearch(f, l, e, arr);
        }
        else if (arr[mid] > e)
        {
            l = mid - 1;
            return BinarySearch(f, l, e, arr);
        }
    }else{
        return -1;
    }
}

int main()
{
    int sz;
    cout << "Size : ";
    cin >> sz;
    int arr[sz];
    cout << "Input array : ";
    for (int i = 0; i < sz; i++)
    {
        cin >> arr[i];
    }
    cout << "Element for found :";
    int ele;
    cin >> ele;
    if (BinarySearch(0, sz-1, ele, arr)!=-1)
    {
        cout << "Total Steps: " << c;
    }else
    {
        cout << "Not found";
    }
}
