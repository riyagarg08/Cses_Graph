#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                count++;
                grid[i][j]='#';
                vector<pair<int,int>> q;
                q.push_back({i,j});
                while(!q.empty()){
                    auto curr=q.back();
                    q.pop_back();
                    int x=curr.first;
                    int y=curr.second;
                    if(x-1>=0 && grid[x-1][y]=='.'){
                        grid[x-1][y]='#';
                        q.push_back({x-1,y});
                    }
                    if(x+1<n && grid[x+1][y]=='.'){
                        grid[x+1][y]='#';
                        q.push_back({x+1,y});
                    }
                    if(y-1>=0 && grid[x][y-1]=='.'){
                        grid[x][y-1]='#';
                        q.push_back({x,y-1});
                    }
                    if(y+1<m && grid[x][y+1]=='.'){
                        grid[x][y+1]='#';
                        q.push_back({x,y+1});
                    }
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}