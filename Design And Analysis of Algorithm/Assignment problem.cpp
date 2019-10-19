#include<bits/stdc++.h>
#define pb push_back
#define sz 100
using namespace std;
int arr[sz][sz];
int n;
int fin ;
int mm=INT_MAX;
vector<int> finalteam;
void fi(int j,int total,int task,vector<int> team){
    //cout << task << " ";
    if(fin==task){
        mm = min(mm,total);
        if(total==mm)
        finalteam = team;
        return ;
    }
    if(j>=n) return ;
    int mn = INT_MAX;
    for(int i=0;i<n;i++)
    {
        int check = 1<<i;
        if(check&task)continue;
        team[j] = i+1;
        fi(j+1,total+arr[j][i],(task|(1<<i)),team);


    }







}

int main()
{


   freopen("in5.txt","r",stdin);
   int t;
   cin >> t;
   while(t--){
   mm=INT_MAX;
   finalteam.clear();
   cin >>n;
   fin = (1<<n)-1;
   vector<int> team(n+1,0);
   //cout << fin << " n" << n;
   for(int person=0;person<n;person++)
    {
    for(int task=0;task<n;task++)
    {
         cin >> arr[person][task];
        // cout << arr[person][task] << " ";
    }
   // cout << endl;
   }
   fi(0,0,0,team);
  cout << mm<<endl;
  for(int person=0;person<n;person++)
    {

   cout << "Person " << person+1 << " task : " << finalteam[person] << endl;
     }


     cout << endl<<endl;
   }



return 0;
}

