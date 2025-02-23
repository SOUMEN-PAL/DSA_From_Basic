#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100000000;

struct Edge {
    int u, v, w;
};

int main() {
    int n, e;
    cin >> n >> e;
    
    vector<Edge> edges(e);
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    int source;
    cin >> source;
    
    // dp[i][v] represents the minimum distance to vertex v using at most i edges.
    vector<vector<int>> dp(n, vector<int>(n, INF));
    
    // Base case: With 0 edges, only the source is reachable at a distance of 0.
    dp[0][source] = 0;
    
    // Iterate for i = 1 to n-1 edges.
    for (int i = 1; i < n; i++) {
        // First, copy the best distances from the previous iteration (using i-1 edges).
        for (int v = 0; v < n; v++) {
            dp[i][v] = dp[i - 1][v];
        }
        // Relax each edge using the distances computed with i-1 edges.
        for (const auto &edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if (dp[i - 1][u] != INF) { // Only relax if u is reachable.
                dp[i][v] = min(dp[i][v], dp[i - 1][u] + w);
            }
        }
    }
    
    // The final row dp[n-1] contains the shortest distances using at most n-1 edges.
    for (int v = 0; v < n; v++) {
        cout << dp[n - 1][v] << " ";
    }
    cout << "\n";
    
    return 0;
}
