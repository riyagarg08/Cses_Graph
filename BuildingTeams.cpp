#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

 bool f(int node,vector<vector<int>>& adj,int col,
    vector<int>& color){
  
    color[node] = col;
    for(auto it:adj[node]){
        if(color[it]==-1){
            if(f(it,adj,1-col,color)==false) return false;
        }
        else if(col==color[it]) return false;
    }
    return true;
}
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
     vector<int> color(n+1,-1);
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(f(i,adj,0,color)==false){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
     }
     for(int i=1;i<=n;i++){
      cout<<color[i]+1<<" ";
     }
     return 0;

}