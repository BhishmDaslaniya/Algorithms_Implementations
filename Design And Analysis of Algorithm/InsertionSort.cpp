#include <bits/stdc++.h>
#include "timer.cpp"
using namespace std;
long long int com = 0;

void InsertionSort(int arr[], int n)
{
    int key,i;
    for(int j = 1 ; j < n ; j++){
        key = arr[j];
        i = j-1;
        while(i >= 0 && arr[i] > key){
            com++;
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

int main()
{
    int inputSize[8] = {50, 500, 1000, 2500, 5000, 10000, 50000, 100000};
    cout << "Generating random numbers and Calculate sorting time!!! Please wait..." << endl;
    cout << "-----------------------------------------------------" << endl;
    for (int x = 0; x < 8; x++)
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
        InsertionSort(arr, n);
        StopTimer();

        timedifference = CalTimeDiff();
        cout << "Array Size            : " << n << endl;
        cout << "Time(In Second)       : " << timedifference << endl;
        cout << "Number of Comparision : " << com << endl;
        cout << "-----------------------------------------------------" << endl;
    }
}