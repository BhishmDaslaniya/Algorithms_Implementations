#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;

bool sortbysec(const pair<ll, ll> &a,const pair<ll, ll> &b)
{
    return (a.second < b.second);
}

void selectActivities(vector < pair <ll, ll> > v) {
    cout<<"Selected Activities are : "<<endl;
    cout<<"("<<v[0].f<<", "<<v[0].s<<"), ";
    ll pre = 0;
    for(ll i = 1 ; i < v.size() ; i++){
        if(v[i].f >= v[pre].s){
            cout << "(" << v[i].f << ", " << v[i].s << "), ";
            pre = i;
        }
    }
}

int main()
{
    cout<<"Enter number of activities : ";
    ll n;
    cin>>n;
    vector<pair< ll,ll > > v;
    ll ts,te;
    cout<<"Enter start time and End time of Activities : "<<endl;
    for(ll i = 0 ; i < n ; i++){
        cout<<"For Activity[ "<<i+1<<" ] : ";
        cin>>ts>>te;
        v.push_back(make_pair(ts,te));
    }
    sort(v.begin(),v.end(),sortbysec);

    selectActivities(v);

}