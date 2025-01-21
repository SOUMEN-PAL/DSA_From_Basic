#include <bits/stdc++.h>
using namespace std;

// Function to add an edge between an employee and a language
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// DFS function to explore the connected components
void DFS(vector<int> adj[], vector<bool>& visited, int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(adj, visited, neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Create an adjacency list for the graph
    vector<int> adj[n + m + 1];  // Employee nodes are 1 to n, language nodes are n+1 to n+m

    // Read the languages known by each employee
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int lang;
            cin >> lang;
            // Add an edge between employee i and language lang
            addEdge(adj, i, n + lang);
        }
    }

    // Vector to track visited nodes
    vector<bool> visited(n + m + 1, false);

    // Count the number of connected components
    int components = 0;

    // Perform DFS on all nodes to find the connected components
    for (int i = 1; i <= n; i++) {  // Only check employee nodes
        if (!visited[i]) {
            components++;
            DFS(adj, visited, i);
        }
    }

    // If no one knows any language, all employees are isolated
    bool anyLanguageKnown = false;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        if (k > 0) {
            anyLanguageKnown = true;
        }
    }

    if (!anyLanguageKnown) {
        cout << n << endl;  // If no one knows any language, all employees are isolated
        return 0;
    }

    // The answer is the number of components minus 1
    cout << components - 1 << endl;

    return 0;
}
