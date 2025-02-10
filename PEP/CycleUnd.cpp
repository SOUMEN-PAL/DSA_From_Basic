#include <iostream>
#include <vector>

using namespace std;

bool DFS(vector<int> adj[], vector<bool> &visited, int v, int parent) {
    visited[v] = true;

    for (auto u : adj[v]) {
        if (!visited[u]) {
            if (DFS(adj, visited, u, v)) {
                return true;
            }
        }
        // If the adjacent node is visited and is not the parent, a cycle exists
        else if (u != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<int> adj[], int V) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (DFS(adj, visited, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V];

    // Example graph with a cycle
    adj[0].push_back(1);
    adj[1].push_back(0);
    
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1); // Back edge creating a cycle
    adj[1].push_back(4);

    if (isCycle(adj, V))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}
