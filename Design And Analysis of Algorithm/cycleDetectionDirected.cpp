#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector< vector <ll> > Graph;
const ll MAX = 10000;

enum Color{
    white,gray,black
};

bool detectCycle(Graph &G){
    Color isVisited[MAX] = {white};
    ll parent[MAX];
    stack< ll > S;
    for(ll i = 0 ; i < G.size() ; i++){
        if(isVisited[i] == black){
            continue;
        }
        S.push(i);
        while(!S.empty()){
            ll u = S.top();
            S.pop();
            if(isVisited[u]==gray){
                isVisited[u] = black;
            }else{
                S.push(u);
                isVisited[u] = gray;
                for(ll i = 0 ; i < G[u].size() ;i++){
                    ll v = G[u][i];
                    if(isVisited[v]==white){
                        parent[v] = u;
                        S.push(v);
                    }else if(isVisited[v] == gray && ( v != parent[u])){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    ll v,e;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;
    Graph G(v);
    cout<<"Enter vertices for edges: "<<endl;
    for(ll i = 0 ; i < e ; i++){
        ll s,e;
        cin>>s>>e;
        s--;
        e--;
        G[s].push_back(e);
    }
    cout<<"Graph has Cycle ? --> ";
    if(detectCycle(G)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}