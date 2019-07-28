#include <bits/stdc++.h>
#include "timer.cpp"
using namespace std;
long long int com = 0;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            com++;
            i++; // increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
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
        quickSort(arr, 0, n);
        StopTimer();

        timedifference = CalTimeDiff();
        cout << "Array Size              : " << n << endl;
        cout << "Time(In Second)         : " << timedifference << endl;
        cout << "Number of swaps : " << com << endl;
        cout << "-----------------------------------------------------" << endl;
    }
}