#include <bits/stdc++.h>
using namespace std;

void printList(vector<vector<pair<long long, long long>>> &graph, long long V) {
    for (long long i = 1; i < V; i++) {
        for (auto data : graph[i]) {
            cout << i << " " << data.first << " " << data.second << endl;
        }
    }
}

vector<pair<long long, pair<long long, long long>>> shortestPath(vector<vector<pair<long long, long long>>> &graph, long long V, long long s, long long p) {
    vector<bool> visited(V, false);
    vector<pair<long long, pair<long long, long long>>> ssst;
    priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;

    pq.push({0, {s, p}});
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        long long wt = curr.first;
        long long node = curr.second.first;
        long long parent = curr.second.second;

        if (visited[node]) {
            continue;
        }
        visited[node] = true;
        ssst.push_back({wt, {node, parent}});

        for (auto &i : graph[node]) {
            long long neighbor = i.first;
            long long weight = i.second;
            if (!visited[neighbor]) {
                pq.push({weight + wt, {neighbor, node}});
            }
        }
    }
    return ssst;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> adj(n + 1);

    for (long long i = 0; i < m; i++) {
        long long u, v, wt;
        cin >> u >> v >> wt;
        // bool updated = false;
        // for (auto &edge : adj[u]) {
        //     if (edge.first == v) {
        //         if (wt < edge.second) {
        //             edge.second = wt; 
        //         }
        //         updated = true;
        //         break;
        //     }
        // }

        
            adj[u].push_back({v, wt});
        
    }

    auto res = shortestPath(adj, n + 1, 1, -1);
    vector<long long> ans(n, 0);
    for (auto i : res) {
        long long wt = i.first;
        long long node = i.second.first;
        ans[node - 1] = wt;
    }

    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}