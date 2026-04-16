#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& parent, int& start, int& end){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            parent[it] = node;
            if(dfs(it, adj, vis, parent, start, end)) return true;
        }
        else if(it != parent[node]){
            start = it;
            end = node;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> vis(n+1, 0);
    vector<int> parent(n+1, -1);
    int start = -1, end = -1;
    bool flag = false;
    
    // Handle disconnected graphs
    for(int i = 1; i <= n && !flag; i++){
        if(!vis[i])
            flag = dfs(i, adj, vis, parent, start, end);
    }
    
    if(!flag){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    // Reconstruct cycle
    vector<int> cycle;
    int cur = end;
    while(cur != start){
        cycle.push_back(cur);
        cur = parent[cur];
    }
    cycle.push_back(start);
    reverse(cycle.begin(), cycle.end());
    cycle.push_back(start); // close the cycle
    
    cout << cycle.size()  << endl; // number of nodes in cycle
    for(auto it: cycle) cout << it << " ";
    cout << endl;
    
    return 0;
}