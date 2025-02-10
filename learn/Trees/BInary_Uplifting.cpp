#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2*1e5;  
vector<vector<int>> adj(MAX_N);
vector<int> in(MAX_N, 0), out(MAX_N, 0);
vector<vector<int>> dp;
int timeCounter = 0;
int l;

void iterativeDFS(int root) {
    stack<pair<int, int>> stk;
    stk.push({root, -1});

    while (!stk.empty()) {
        auto [node, parent] = stk.top();
        stk.pop();

        dp[node][0] = parent;
        for (int i = 1; i <= l; i++) {
            if (dp[node][i - 1] != -1) {
                dp[node][i] = dp[dp[node][i - 1]][i - 1];
            } else {
                dp[node][i] = -1;
            }
        }

        in[node] = timeCounter++;
        for (int i : adj[node]) {
            if (i == parent) continue;
            stk.push({i, node});
        }
        out[node] = timeCounter++;
    }
}

int ktTh(int node, int k) {
    int m = ceil(log2(k));
    for (int i = 0; i <= m; i++) {  
        if (k & (1 << i)) {
            node = dp[node][i];
            if (node == -1) return -1;
        }
    }
    return node;
}

bool is_ancestor(int u, int v)
{
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(dp[u][i], v))
            u = dp[u][i];
    }
    return dp[u][0];
}


int main() {
    int n, q;
    cin >> n >> q;

    l = log2(n) + 1;
    adj.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(l + 1, -1));

    for (int i = 2; i <= n; i++) {
        int edge;
        cin >> edge;
        adj[edge].push_back(i);
    }

    iterativeDFS(1);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << ktTh(a, b) << '\n';
    }

    return 0;
}
