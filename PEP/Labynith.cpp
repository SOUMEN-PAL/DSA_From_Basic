#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    pair<int, int> start, end;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'A') {
                start = {i, j};
            } else if (mat[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    vector<vector<int>> parent(n, vector<int>(m, -1));
    vector<vector<char>> direction(n, vector<char>(m, ' '));
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    int dirX[] = {0, 1, 0, -1};
    int dirY[] = {1, 0, -1, 0};
    char dir[] = {'R', 'D', 'L', 'U'};

    bool found = false;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == end.first && y == end.second) {
            found = true;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dirX[k];
            int ny = y + dirY[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (mat[nx][ny] == '.' || mat[nx][ny] == 'B')) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                parent[nx][ny] = k;
                direction[nx][ny] = dir[k];
            }
        }
    }

    if (found) {
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