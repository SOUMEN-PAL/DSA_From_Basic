#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

int dia = 0;

int diameter(vector<int> adj[], int parent, int node) {
    int maxH = 0; // Initialize maxH to 0
    for (auto i : adj[node]) {
        if (i == parent) {
            continue;
        }

        int h = diameter(adj, node, i);
        dia = max(dia, maxH + h + 1);
        maxH = max(maxH, h + 1);
    }
    return maxH;
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

    dia = 0; // Reset dia before calling diameter
    diameter(adj, -1, 0); // Start from node 0 (0-based indexing)
    cout << dia << endl;

    return 0;
}