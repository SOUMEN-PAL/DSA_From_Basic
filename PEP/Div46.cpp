#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> freq(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<vector<int>> adj(n + 1);
        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> valid(n + 1, false);

        for (int x = 1; x <= n; x++) {
            if (freq[x] < 2)
                valid[x] = false;
        }

        for (int u = 1; u <= n; u++) {
            for (int v : adj[u]) {
                if (u < v) {
                    if (a[u] == a[v]) {
                        valid[a[u]] = true;
                    }
                }
            }
        }

        for (int v = 1; v <= n; v++) {
            if (adj[v].size() < 2) continue;
            unordered_map<int, int> count;
            for (int nb : adj[v]) {
                count[a[nb]]++;
            }
            for (auto& p : count) {
                int cand = p.first;
                int cnt = p.second;
                if (cnt >= 2) {
                    valid[cand] = true;
                }
            }
        }

        string ans;
        ans.resize(n);
        for (int x = 1; x <= n; x++) {
            ans[x - 1] = valid[x] ? '1' : '0';
        }

        cout << ans << "\n";
    }
    return 0;
}
