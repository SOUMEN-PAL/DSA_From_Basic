#include <bits/stdc++.h>
using namespace std;
 
// Function to add a directed edge u -> v with weight wt
void addEdge(vector<vector<pair<int,int>>>& adj, int u, int v, int wt) {
    adj[u].push_back({v, wt});
}
 
// Recursive function to print the path from the source to 'dest' using the parent array.
void printPath(int dest, const vector<int>& parent) {
    if(dest == -1)
        return;
    printPath(parent[dest], parent);
    cout << dest << " ";
}
 
int main(){
    int v = 3; // number of vertices (nodes are numbered 0, 1, 2)
    
    // Create an adjacency list for a directed graph
    vector<vector<pair<int,int>>> adj(v);
    addEdge(adj, 0, 1, 6);
    addEdge(adj, 0, 2, 2);
    addEdge(adj, 2, 1, 3);
    
    int source = 0;  // Starting from node 0

    // Initialize distance and parent vectors.
    const int INF = INT_MAX;
    vector<int> dist(v, INF);
    vector<int> parent(v, -1);
    dist[source] = 0;
    
    // Min-heap priority queue: (distance, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});
    
    // Standard Dijkstra's algorithm
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        
        // If the popped distance is not up-to-date, skip it.
        if(d != dist[u])
            continue;
        
        // Relaxation step for all adjacent vertices
        for(auto &edge : adj[u]){
            int v = edge.first;
            int w = edge.second;
            if(dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;  // Record the parent (predecessor) for v
                pq.push({dist[v], v});
            }
        }
    }
    
    // Print the shortest path from source to each vertex
    for (int i = 0; i < v; i++){
        cout << "Shortest path from " << source << " to " << i << ": ";
        if(dist[i] == INF){
            cout << "No path";
        } else {
            printPath(i, parent);
            cout << " (Total cost: " << dist[i] << ")";
        }
        cout << "\n";
    }
    
    return 0;
}
