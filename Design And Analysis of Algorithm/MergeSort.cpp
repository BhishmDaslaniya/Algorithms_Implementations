#include <bits/stdc++.h>
#include "timer.cpp"
using namespace std;
long long int com = 0;

void merge(int arr[], int l, int m, int r)
{
    com++;
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    com++;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int inputSize[10] = {50, 500, 1000, 2500, 5000, 10000, 50000, 100000, 150000, 200000};
    cout << "Generating random numbers and Calculate sorting time!!! Please wait..." << endl;
    cout << "-----------------------------------------------------" << endl;
    for (int x = 0; x < 10; x++)
    {
        com = 0;
        int n = inputSize[x];
        int arr[n];
        double timedifference;

        for (int i = 0; i < n; i++)
        {
            arr[i] = rand();
        }

        StartTimer();
        mergeSort(arr,0,n);
        StopTimer();

        timedifference = CalTimeDiff();
        cout << "Array Size              : " << n << endl;
        cout << "Time(In Second)         : " << timedifference << endl;
        cout << "Number of Function call : " << com << endl;
        cout << "-----------------------------------------------------" << endl;
    }
}