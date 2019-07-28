#include <bits/stdc++.h>
#include "timer.cpp"
using namespace std;
long long int com = 0;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int arr[], int n)
{
    int minIndex;
    for(int i = 0 ; i < n-1 ; i++){
        minIndex = i;
        for(int j = i+1 ; j < n ;j++){
            if(arr[j] < arr[minIndex]){
                com++;
                minIndex = j;
            }
        }
        swap(&arr[minIndex],&arr[i]);
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
        SelectionSort(arr, n);
        StopTimer();
        timedifference = CalTimeDiff();

        cout << "Array Size            : " << n << endl;
        cout << "Time(In Second)       : " << timedifference << endl;
        cout << "Number of Comparision : " << com << endl;
        cout << "-----------------------------------------------------" << endl;
    }
}