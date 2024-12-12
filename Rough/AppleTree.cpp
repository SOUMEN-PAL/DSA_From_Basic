#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> cnt;

void dfs(int v, int parent) {
    cnt[v] = 0;
    bool isLeaf = true;

    for (auto u : adj[v]) {
        if (u != parent) {
            isLeaf = false;
            dfs(u, v);
            cnt[v] += cnt[u];
        }
    }

    if (isLeaf) cnt[v] = 1; // Mark as leaf
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int v;
        cin >> v;
        
        adj.assign(v + 1, vector<int>());
        cnt.assign(v + 1, 0);

        for (int i = 0; i < v - 1; i++) {
            int u, w;
            cin >> u >> w;
            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        dfs(1, -1); // Assuming 1-based indexing and node 1 as the root

        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            cout << 1LL * cnt[x] * cnt[y] << endl; // Multiply subtree leaf counts
        }
    }

    return 0;
}
