#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &parent, int v, int par, vector<int> &cycle) {
    visited[v] = true;
    parent[v] = par;
    
    for (int u : adj[v]) {
        if (!visited[u]) {
            if (DFS(adj, visited, parent, u, v, cycle))
                return true;
        } else if (u != par) {
            
            cycle.push_back(u);          
            for (int cur = v; cur != u; cur = parent[cur])
                cycle.push_back(cur);
            cycle.push_back(u);           
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<int> cycle;
    
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (DFS(adj, visited, parent, i, -1, cycle)) {
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for (int city : cycle) {
            cout << city << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
