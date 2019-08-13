#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second   
typedef long long ll;
typedef long double ld;

bool sortBySecDec(const pair<pair<ll, ll>, ld> &a, const pair<pair<ll, ll>, ld> &b)
{
    return a.second > b.second;
}

ld Greedy_knapsack(vector < pair < pair <ll, ll>, ld> > v, ld capacity)
{
    ld maxProfit = 0;
    ll index = 0;
    for(ll i = 0 ; i < v.size(); i++){
        if(capacity > 0 && v[i].f.s <= capacity){
            capacity = capacity - v[i].f.s;
            maxProfit = maxProfit + v[i].f.f;
        }else{
            index = i;
            break;
        }
    }

    if (capacity > 0)
    {
        maxProfit = maxProfit + (v[index].s * capacity);
    }

    return maxProfit;
}

int  main()
{
    cout<<"Enter capacity of Knapsack : ";
    ld capacity;
    cin>>capacity;
    cout << "--------------------------------------------------" << endl;
    cout<<"Enter number of Items :";
    ll n;
    cin>>n;
    vector < pair < pair<ll ,ll> , ld > > v;
    cout << "--------------------------------------------------" << endl;
    cout<<"Enter profit and weight for items: "<<endl;
    pair< ll ,ll > tempPair;
    ll tw,tp;
    for(ll i = 0 ; i  < n ; i++){
        cout<<"For item[ "<<i+1<<" ] :  ";
        cin>>tp>>tw;
        tempPair = make_pair (tp,tw); 
        ld tempRatio = (ld(tp)/ld(tw));
        v.push_back(make_pair(tempPair,tempRatio));
    }
    sort(v.begin(),v.end(),sortBySecDec);
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Max Profit with fractional knapsack = "<<Greedy_knapsack(v,capacity)<<endl;
    cout << "--------------------------------------------------" << endl;
}