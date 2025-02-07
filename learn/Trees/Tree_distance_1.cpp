#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs1(int u, int p, const vector<vector<int>>& adj, vector<int>& best, vector<int>& sbest) {
    best[u] = 0;
    sbest[u] = 0;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs1(v, u, adj, best, sbest);
        int h = best[v] + 1;
        if (h > best[u]) {
            sbest[u] = best[u];
            best[u] = h;
        }
        else if (h > sbest[u]) {
            sbest[u] = h;
        }
    }
}

void dfs2(int u, int p, const vector<vector<int>>& adj,const vector<int>& best, const vector<int>& sbest, vector<int>& ans, int up) {

    ans[u] = max(best[u], up);

    for (int v : adj[u]) {
        if (v == p)
            continue;
        int use = (best[u] == best[v] + 1) ? sbest[u] : best[u];
        dfs2(v, u, adj, best, sbest, ans, max(up, use) + 1);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> best(n, 0), sbest(n, 0);
    vector<int> ans(n, 0);

    dfs1(0, -1, adj, best, sbest);
    dfs2(0, -1, adj, best, sbest, ans, 0);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
