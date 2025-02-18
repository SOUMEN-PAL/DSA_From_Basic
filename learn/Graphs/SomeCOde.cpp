#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void BFS(unordered_map<int, unordered_map<int, int>>& adj, vector<bool>& visited, int src, vector<int>& dist, vector<int>& rq) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;
    rq[src] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (const auto& neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            if (!visited[nextNode]) {
                visited[nextNode] = true;
                dist[nextNode] = dist[node] + 1;
                rq[nextNode] = rq[node] + weight;
                q.push(nextNode);
            }

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, rc;
    cin >> n;

    unordered_map<int, unordered_map<int, int>> adj;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> rc;
        adj[a][b] = rc;
        adj[b][a] = rc;
    }

    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 0);
    vector<int> rq(n + 1, 0);

    BFS(adj, visited, 1, dist, rq);

    vector<int> leaders;
    for (int i = 2; i <= n; i++) {
        if (rq[i] > dist[i])
            leaders.push_back(i);
    }

    cout << leaders.size() << "\n";
    for (int x : leaders) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
