#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void FindSubset(ll pos , ll subsetSum , ll sum,ll d, ll s[] , bool flag[]){
    if((subsetSum+sum >= d) && ((subsetSum==d) || (subsetSum+s[pos+1] <= d))){
        if(subsetSum == d){
            cout<<"\n{ ";
                for(int i = 0 ; i <= pos ; i++){
                    if(flag[i]){
                        cout<<s[i]<<" ";
                    }
                }
            cout<<"}";
        }else{
            flag[pos + 1] = true;
            FindSubset(pos + 1, subsetSum + s[pos + 1], sum - s[pos + 1], d, s, flag);
            flag[pos + 1] = false;
            FindSubset(pos + 1, subsetSum, sum - s[pos + 1], d, s, flag);
        }
    }
}

int main(){
    ll s;
    cout<<"Input size of set:";
    cin>>s;
    ll Mset[s];
    bool flag[s] = {false};
    ll sum = 0;
    for(int i = 0 ; i < s ; i++){
        cin>>Mset[i];
        sum+=Mset[i];
    }

    ll d;
    cout<<"Input d:";
    cin>>d;

    sort(Mset,Mset+s);
    
    if(Mset[0] > d || sum < d){
        cout<<"Not possible"<<endl;
    }else{
        //Apply backtracking!!!
        FindSubset(-1,0,sum,d,Mset,flag);
    }
}