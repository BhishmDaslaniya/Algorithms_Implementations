#include<bits/stdc++.h>
#include "timer.cpp"
using namespace std;
long long int com = 0;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int arr[],int n){
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                com++;
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int main(){
    int inputSize[8] = {50,500,1000,2500,5000,10000,50000,100000};
    cout << "Generating random numbers and Calculate sorting time!!! Please wait..." << endl;
    cout << "-----------------------------------------------------" << endl;
    for(int x = 0 ; x < 8 ; x++){
        com = 0;
        int n = inputSize[x];    
        int arr[n];
        double timedifference;
        
        for(int i = 0 ; i < n ; i++){
            arr[i] = rand();
        }

        StartTimer();
        BubbleSort(arr,n);
        StopTimer();
        timedifference = CalTimeDiff();
        cout<<"Array Size            : "<<n<<endl;
        cout<<"Time(In Second)       : "<<timedifference<<endl;
        cout<<"Number of Comparision : "<<com<<endl;
        cout<<"-----------------------------------------------------"<<endl;
    }  
}