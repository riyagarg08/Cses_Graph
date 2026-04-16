#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,long long>> edges;

    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<long long> dist(n+1, -1e18);
    dist[1] = 0;

    // Step 1: Relax edges n-1 times
    for(int i = 1; i <= n-1; i++){
        for(auto [u,v,w] : edges){
            if(dist[u] != -1e18 && dist[u] + w > dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 2: Detect positive cycle affecting answer
    vector<bool> affected(n+1, false);

    for(int i = 1; i <= n; i++){
        for(auto [u,v,w] : edges){
            if(dist[u] != -1e18 && dist[u] + w > dist[v]){
                dist[v] = dist[u] + w;
                affected[v] = true;
            }
            if(affected[u]) affected[v] = true;
        }
    }

    // Step 3: If node n affected → infinite
    if(affected[n]){
        cout << -1 << "\n";
    }
    else{
        cout << dist[n] << "\n";
    }

    return 0;
}