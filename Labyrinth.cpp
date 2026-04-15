#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'U', 'L', 'R', 'D'};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    queue<pair<int,int>> q;
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> move(n, vector<char>(m));

    // find A
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                q.push({i, j});
                grid[i][j] = '#'; // mark visited
            }
        }
    }

    pair<int,int> end = {-1,-1};

    // BFS
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                
                parent[nx][ny] = {x, y};
                move[nx][ny] = dir[k];

                if(grid[nx][ny] == 'B') {
                    end = {nx, ny};
                    break;
                }

                grid[nx][ny] = '#';
                q.push({nx, ny});
            }
        }
        if(end.first != -1) break;
    }

    // if not found
    if(end.first == -1) {
        cout << "NO\n";
        return 0;
    }

    // reconstruct path
    string path;
    pair<int,int> cur = end;

    while(parent[cur.first][cur.second] != make_pair(-1,-1)) {
        path += move[cur.first][cur.second];
        cur = parent[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}