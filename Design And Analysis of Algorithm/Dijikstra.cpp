#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(n,m) memset(n,m,sizeof(n))
ll mat[2005][2005];
ll dist[2005];
bool sptSet[2005];
ll V;

int minDistance() 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v <= V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
void dijkstra( ll src , ll dest) 
{     
    dist[src] = 0; 
  
    for (int count = 0; count <= V; count++) { 
    
        int u = minDistance(); 

        sptSet[u] = true; 
  
        for (int v = 0; v <= V; v++) 
            if (!sptSet[v] && mat[u][v] && dist[u] != INT_MAX 
                && dist[u] + mat[u][v] < dist[v]) 
                dist[v] = dist[u] + mat[u][v]; 
    } 
  
    if(dist[dest]!= INT_MAX){
        cout<<"Shortest distance between "<<src<<" to  "<<dest<<" is "<<dist[dest]<<endl;
    }else{
        cout<<"Path is not possible!!!\n";
    }
} 

int main(){
    for(ll i = 0 ; i < 2005 ; i++){
        for(ll j = 0 ; j < 2005 ; j++){
            mat[i][j] = INT_MAX;
        }
    }
    for(ll i = 0 ; i < 2005 ; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    ll m,a,b;
    V = 0;
    cout<<"Enter total number of edges:";
    cin>>m;
    cout<<"Enter the values for edges with weight:\n";
    cout<<"Format of entering values (start weight end):::\n";
    ll x,y,z;
    for(ll i = 0 ; i < m ; i++){
        cin>>x>>y>>z;
        V = max(V,max(x,z));
        mat[x][z] = min(mat[x][z],y);
        mat[z][x] = min(mat[z][x],y);
    }
    cout<<"Enter Source vertex and destination vertex for shortest path:";
    cin>>a>>b;
    dijkstra(a,b);
    return 0;    
}