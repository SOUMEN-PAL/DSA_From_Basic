#include<bits/stdc++.h>
using namespace std;






int main(){
    
    return 0;
}









/*
#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, int p, const vector<vector<long long>>& adj, vector<long long>& subtree_size, vector<long long>& subtree_sum) {
    subtree_size[u] = 1;
    subtree_sum[u] = 0;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs1(v, u, adj, subtree_size, subtree_sum);
        subtree_size[u] += subtree_size[v];
        subtree_sum[u] += subtree_sum[v] + subtree_size[v];
    }
}

void dfs2(long long u, long long p, const vector<vector<long long>>& adj, vector<long long>& subtree_size, vector<long long>& subtree_sum, vector<long long>& result, long long n) {
    result[u] = subtree_sum[u];
    
    for (int v : adj[u]) {
        if (v == p)
            continue;
        
        // Backup original values before modifying them
        int original_u_sum = subtree_sum[u];
        int original_v_sum = subtree_sum[v];
        int original_u_size = subtree_size[u];
        int original_v_size = subtree_size[v];

        // Shift the root from `u` to `v`
        subtree_sum[u] -= (subtree_sum[v] + subtree_size[v]);
        subtree_size[u] -= subtree_size[v];

        subtree_sum[v] += (subtree_sum[u] + subtree_size[u]);
        subtree_size[v] += subtree_size[u];

        dfs2(v, u, adj, subtree_size, subtree_sum, result, n);

        // Restore original values
        subtree_sum[u] = original_u_sum;
        subtree_sum[v] = original_v_sum;
        subtree_size[u] = original_u_size;
        subtree_size[v] = original_v_size;
    }
}

int main() {
    long long n;
    cin >> n;
    vector<vector<long long>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Convert to 0-based indexing
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<long long> subtree_size(n, 0), subtree_sum(n, 0), result(n, 0);
    dfs1(0, -1, adj, subtree_size, subtree_sum);
    dfs2(0, -1, adj, subtree_size, subtree_sum, result, n);

    for (long long i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/