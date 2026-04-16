#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long long>>> adj(n+1);
     for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
     }
     priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
     vector<long long> dist(n+1,1e18);
     pq.push({0,1});
     dist[1] = 0;
     while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d>dist[node]) continue;
        for(auto it: adj[node]){
            int newNode = it.first;
            int wt = it.second;
            if(dist[newNode]>dist[node]+wt){
                dist[newNode] = dist[node]+wt;
                pq.push({dist[newNode], newNode});
            }
        }

     }
     for(int i=1;i<=n;i++){
        if(dist[i]==1e18) cout<<"-1 ";
        else cout<<dist[i]<<" ";
     }
     return 0;  
}
