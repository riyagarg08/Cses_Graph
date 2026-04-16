#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};   
char dir[4]={'U','R','D','L'};

void f(queue<pair<int,int>>& q, vector<vector<int>>& dist, vector<vector<char>>& adj, int n, int m){
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0 && newx<n && newy>=0 && newy<m && adj[newx][newy]!='#' && dist[newx][newy]>dist[x][y]+1){
                dist[newx][newy] = min(dist[newx][newy], dist[x][y]+1);
                
                q.push({newx,newy});
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> adj(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j]; 
        }
    }
    vector<vector<int>> dist(n,vector<int>(m,1e7));
    vector<vector<int>> distA(n,vector<int>(m,1e7));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
    queue<pair<int,int>> q;
    vector<vector<char>> move(n,vector<char>(m));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]=='M'){
                q.push({i,j});
                dist[i][j]=0;

            }
        }
    }
    f(q,dist,adj,n,m);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //       cout<<dist[i][j]<<" ";
    //     }
    // }
    queue<pair<int,pair<int,int>>> q1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]=='A'){
                q1.push({0,{i,j}});
               distA[i][j]=0;
               move[i][j]='M';
            }
        }
    }
    while(!q1.empty()){
        auto t = q1.front();
        q1.pop();
        int time = t.first;
        int x = t.second.first;
        int y = t.second.second;
        if(x==0 || x==n-1 || y==0 || y==m-1){
           
          string ans;
            ans.push_back(move[x][y]);
            while(parent[x][y].first!=-1 && parent[x][y].second!=-1){
                ans.push_back(move[x][y]);
                int px = parent[x][y].first;
                int py = parent[x][y].second;
                x=px;
                y=py;
            }
            reverse(ans.begin(), ans.end());
            ans.pop_back();
            cout<<"YES"<<endl;
            cout<<ans.size()<<endl;
            for(auto it: ans) cout<<it;
            return 0;
        }
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(newx>=0 && newx<n && newy>=0 && newy<m 
   && adj[newx][newy]!='#' 
   && time+1 < dist[newx][newy]   // monster se safe
   && distA[newx][newy] == 1e7)   // not visited
{
    distA[newx][newy] = time+1;   // mark visited
    parent[newx][newy] = {x,y};
    move[newx][newy] = dir[i];
    q1.push({time+1,{newx,newy}});
}
        }
    } 
    cout<<"NO"<<endl;
     return 0;  
}
