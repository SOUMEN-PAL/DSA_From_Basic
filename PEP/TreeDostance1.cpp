#include <bits/stdc++.h>
using namespace std;

int first_last_max(vector<int> adj[], int node, int parent, vector<int> &firstH, vector<int> &secondH) {
    int max_h1 = 0, max_h2 = 0;
    for (auto i : adj[node]) {
        if (i == parent) {
            continue;
        }

        int h = first_last_max(adj, i, node, firstH, secondH);
        if (h + 1 > max_h1) {
            max_h2 = max_h1;
            max_h1 = h + 1;
        } else if (h + 1 > max_h2) {
            max_h2 = h + 1;
        }
    }
    firstH[node] = max_h1;
    secondH[node] = max_h2;
    return max_h1;
}

int main() {
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1); // Use 0-based indexing
        adj[b - 1].push_back(a - 1); // Use 0-based indexing
    }

    vector<int> firstH(n, 0), secondH(n, 0);
    first_last_max(adj, 0, -1, firstH, secondH);

    for (int i = 0; i < n; i++) {
        cout << "Node " << i + 1 << ": First Max Height = " << firstH[i] << ", Second Max Height = " << secondH[i] << endl;
    }

    return 0;
}