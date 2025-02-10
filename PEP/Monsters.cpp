#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    queue<pair<int, int>> q;
    pair<int, int> start;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<int>> monsterDist(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<char>> direction(n, vector<char>(m, ' '));
    vector<vector<int>> parent(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'M') {
                q.push({i, j});
                monsterDist[i][j] = 0;
            }
            if (mat[i][j] == 'A') {
                start = {i, j};
                dist[i][j] = 0;
            }
        }
    }

    int dirX[] = {0, 1, 0, -1};
    int dirY[] = {1, 0, -1, 0};
    char dir[] = {'R', 'D', 'L', 'U'};

    // BFS for monsters
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dirX[k];
            int ny = y + dirY[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == '.' && monsterDist[nx][ny] == INT_MAX) {
                q.push({nx, ny});
                monsterDist[nx][ny] = monsterDist[x][y] + 1;
            }
        }
    }

    // BFS for player
    q.push(start);
    visited[start.first][start.second] = true;
    bool possible = false;
    pair<int, int> end;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            possible = true;
            end = {x, y};
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dirX[k];
            int ny = y + dirY[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == '.' && !visited[nx][ny] && dist[x][y] + 1 < monsterDist[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                direction[nx][ny] = dir[k];
                parent[nx][ny] = k;
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
        string path;
        int x = end.first, y = end.second;
        while (make_pair(x, y) != start) {
            path += direction[x][y];
            int k = parent[x][y];
            x -= dirX[k];
            y -= dirY[k];
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}