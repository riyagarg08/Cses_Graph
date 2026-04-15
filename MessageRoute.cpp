#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
     vector<vector<int>> adj(n+1);
     for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
     vector<int> vis(n+1,0);
     vector<int> parent(n+1,-1);
    pq.push({1,1});
    vis[1]=1;
    int x=0;
    while(!pq.empty()){
        int t = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(node==n){
            x=t;
            break;
        }
       
       for(auto it: adj[node]){
        if(!vis[it]){
            vis[it] = 1;
            parent[it] = node;
            pq.push({t+1,it});
        }
    }
    }
    if(vis[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<x<<endl;
    vector<int> temp;
    while(parent[n]!=-1){
       temp.push_back(n);
        n = parent[n];
    }
    temp.push_back(n);
    reverse(temp.begin(), temp.end());
    for(auto it: temp) cout<<it<<" ";
     return 0;
}