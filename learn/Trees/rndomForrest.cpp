#include <bits/stdc++.h>
using namespace std;

class ForestLCA {
public:
    int n;  // Number of nodes
    vector<vector<int>> tree;  // Adjacency list
    vector<int> parent, depth;
    unordered_set<int> roots;  // Store roots of the forest

    ForestLCA(int n) {
        this->n = n;
        tree.resize(n + 1);
        parent.assign(n + 1, -1);
        depth.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) roots.insert(i);  // Assume 1-based indexing
    }

    void addEdge(int u, int v) {
        tree[u].push_back(v);
        tree[v].push_back(u);
        roots.erase(v);  // v is a child, remove from root set
    }

    void dfs(int node, int par, int d) {
        parent[node] = par;
        depth[node] = d;
        for (int neighbor : tree[node]) {
            if (neighbor != par) {
                dfs(neighbor, node, d + 1);
            }
        }
    }

    void preprocess() {
        for (int root : roots) {
            dfs(root, -1, 0);
        }
    }

    int findLCA(int u, int v) {
        if (parent[u] == -1 || parent[v] == -1) return -1;  // Nodes in different trees

        // Ensure u is the deeper node
        if (depth[u] < depth[v]) swap(u, v);

        // Bring u to the same level as v
        while (depth[u] > depth[v]) {
            u = parent[u];
        }

        // Move both up until they meet
        while (u != v) {
            u = parent[u];
            v = parent[v];
        }

        return u;
    }
};

int main() {
    int n = 7;
    ForestLCA lcaSolver(n);

    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {4, 5}, {5, 6}};
    for (auto [u, v] : edges) {
        lcaSolver.addEdge(u, v);
    }

    lcaSolver.preprocess();

    cout << "LCA of 2 and 3: " << lcaSolver.findLCA(2, 3) << endl;  // Output: 1
    cout << "LCA of 5 and 6: " << lcaSolver.findLCA(5, 6) << endl;  // Output: 5
    cout << "LCA of 2 and 6: " << lcaSolver.findLCA(2, 6) << endl;  // Output: -1 (different trees)

    return 0;
}
