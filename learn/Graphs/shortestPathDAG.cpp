#include<bits/stdc++.h>
using namespace std;
// Function to find the shortest path in a DAG using BFS-based topological sort (Kahn's Algorithm)
void shortestPath(int source, const vector<vector<pair<int, int>>>& adj, int V) {
    vector<int> indegree(V, 0);
    vector<int> dist(V, INT_MAX);

    // Calculate indegree for all vertices
    for (int i = 0; i < V; i++) {
        for (auto& neighbor : adj[i]) {
            indegree[neighbor.first]++;
        }
    }

    // BFS Topological Sort (Kahn's Algorithm)
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Initialize the distance to the source node as 0
    dist[source] = 0;

    // Process vertices in topological order
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // For each neighbor of u, relax the edge (u -> v)
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relax the edge if a shorter path is found
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }

            // Reduce the indegree and push v to the queue if indegree becomes 0
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Print the calculated shortest distances
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // Example graph: (source, destination, weight)
    adj[0].push_back({1 , 1});
    adj[2].push_back({0 , 1});
    adj[2].push_back({3 , 1});
    adj[2].push_back({4 , 1});

    int source = 2;
    shortestPath(source, adj, V);

    return 0;
}