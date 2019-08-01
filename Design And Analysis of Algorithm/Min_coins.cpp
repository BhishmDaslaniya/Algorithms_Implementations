#include<bits/stdc++.h>
using namespace std;

void findMinCoins(int TotalCost,int denominations[],int n){
    // int ans[n] = {0};
    vector<int> ans;
    // int j = 0;
    sort(denominations,denominations+n);
    for(int i = n-1 ; i>=0 ;i--){
        while(TotalCost >= denominations[i]){
            TotalCost-=denominations[i];
            // ans[j++]  = denominations[i]; 
            ans.push_back(denominations[i]);
        }
    }
    // cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main(){
    int TotalCost;
    cout <<"Enter Total cost : ";
    cin>> TotalCost;
    int n;
    cout << "Enter Total number of available coins : ";
    cin>>n;
    cout<<"Enter denominations values : ";
    int denominations[n];
    for(int i = 0 ; i < n ; i++){
        cin>>denominations[i];
    }
    findMinCoins(TotalCost, denominations , n);
}