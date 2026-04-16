#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> adj(n+1, vector<long long>(n+1, 1e18));
     for(int i=0;i<m;i++){
       int u,v,w;
        cin >> u >> v >> w;
       adj[u][v] = min(adj[u][v], (long long)w);
adj[v][u] = min(adj[v][u], (long long)w);
     }
     for(int i=1;i<=n;i++){
        adj[i][i] = 0;
     }
     for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
     }
     while(q--){
        int u,v;
        cin >> u >> v;      
        if(adj[u][v]==1e18) cout<<"-1\n";
        else cout<<adj[u][v]<<"\n";
     }
     return 0;  
}
