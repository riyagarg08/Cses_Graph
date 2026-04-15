#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'U', 'L', 'R', 'D'};

void f(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            f(it, adj, vis);
        }
    }
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
     int c=0;
      vector<int> temp;
        vector<bool> vis(n+1,false);
        for(int i=1;i<=n;i++){
           if(!vis[i]){
            f(i,adj,vis);
            c++;
            temp.push_back(i);
           }
            
        }
        cout<<c-1<<endl;
        for(int i=0;i<temp.size()-1;i++){
            cout<<temp[i]<<" "<<temp[i+1]<<endl;    
        }

}