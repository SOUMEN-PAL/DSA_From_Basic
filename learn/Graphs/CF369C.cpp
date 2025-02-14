#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
vector<pair<int, int>> adj[N];
vector<int> ans;
bool got[N];

void dfs(int u, int p) {
    for (auto &edge : adj[u]) {
        int v = edge.first, t = edge.second;
        if (v == p) continue;
        dfs(v, u);
        if (t == 2 && !got[v]) {
            ans.push_back(v);
            got[v] = true;
        }
        if (got[v]) {
            got[u] = true;
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        adj[i].clear();
        got[i] = false;
    }
    
    for (int i = 1; i <= n - 1; i++){
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    
    dfs(1, -1);
    
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
    
    return 0;
}
