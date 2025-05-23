// #include <bits/stdc++.h>
// using namespace std;

// void printList(vector<vector<pair<long long, long long>>> &graph, long long V) {
//     for (long long i = 1; i < V; i++) {
//         for (auto data : graph[i]) {
//             cout << i << " " << data.first << " " << data.second << endl;
//         }
//     }
// }

// vector<pair<long long, pair<long long, long long>>> shortestPath(vector<vector<pair<long long, long long>>> &graph, long long V, long long s, long long p) {
//     vector<bool> visited(V, false);
//     vector<pair<long long, pair<long long, long long>>> ssst;
//     priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;

//     pq.push({0, {s, p}});
    
//     while (!pq.empty()) {
//         auto curr = pq.top();
//         pq.pop();

//         long long wt = curr.first;
//         long long node = curr.second.first;
//         long long parent = curr.second.second;

//         if (visited[node]) {
//             continue;
//         }
//         visited[node] = true;
//         ssst.push_back({wt, {node, parent}});

//         for (auto &i : graph[node]) {
//             long long neighbor = i.first;
//             long long weight = i.second;
//             if (!visited[neighbor]) {
//                 pq.push({weight + wt, {neighbor, node}});
//             }
//         }
//     }
//     return ssst;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     long long n, m;
//     cin >> n >> m;

//     vector<vector<pair<long long, long long>>> adj(n + 1);

//     for (long long i = 0; i < m; i++) {
//         long long u, v, wt;
//         cin >> u >> v >> wt;
//         // bool updated = false;
//         // for (auto &edge : adj[u]) {
//         //     if (edge.first == v) {
//         //         if (wt < edge.second) {
//         //             edge.second = wt; 
//         //         }
//         //         updated = true;
//         //         break;
//         //     }
//         // }

        
//             adj[u].push_back({v, wt});
        
//     }

//     auto res = shortestPath(adj, n + 1, 1, -1);
//     vector<long long> ans(n, 0);
//     for (auto i : res) {
//         long long wt = i.first;
//         long long node = i.second.first;
//         ans[node - 1] = wt;
//     }

//     for (auto i : ans) {
//         cout << i << " ";
//     }
//     cout << endl;
    
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;

typedef vector<vector<pll>> Graph;

typedef priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> MinHeap;

void printList(Graph &graph, ll V) {
    for (ll i = 1; i < V; i++) {
        for (auto data : graph[i]) {
            cout << i << " " << data.first << " " << data.second << endl;
        }
    }
}

vector<pair<ll, pll>> shortestPath(Graph &graph, ll V, ll s, ll p) {
    vector<bool> visited(V, false);
    vector<pair<ll, pll>> ssst;
    MinHeap pq;

    pq.push({0, {s, p}});
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        ll wt = curr.first;
        ll node = curr.second.first;
        ll parent = curr.second.second;

        if (visited[node]) continue;

        visited[node] = true;
        ssst.push_back({wt, {node, parent}});

        for (auto &i : graph[node]) {
            ll neighbor = i.first;
            ll weight = i.second;
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

    ll n, m;
    cin >> n >> m;

    Graph adj(n + 1);
    unordered_map<ll, unordered_map<ll, ll>> edgeMap;

    for (ll i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;

        if (edgeMap[u].find(v) == edgeMap[u].end() || wt < edgeMap[u][v]) {
            edgeMap[u][v] = wt;
        }
    }

    for (auto &node : edgeMap) {
        for (auto &edge : node.second) {
            adj[node.first].push_back({edge.first, edge.second});
        }
    }

    auto res = shortestPath(adj, n + 1, 1, -1);
    vector<ll> ans(n, LLONG_MAX);
    
    for (auto i : res) {
        ll wt = i.first;
        ll node = i.second.first;
        ans[node - 1] = wt;
    }

    for (auto i : ans) {
        cout << (i == LLONG_MAX ? -1 : i) << " ";
    }
    cout << endl;
    
    return 0;
}
