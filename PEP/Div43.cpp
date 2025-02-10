#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int j = 0; j < m; j++) {
            cin >> b[j];
        }
        sort(b.begin(), b.end());
        const long long NEG_INF = -1e18;
        const long long INF = 1e18;
        long long current = NEG_INF;
        bool possible = true;
        for (int i = 0; i < n; i++) {
            long long cand = INF;
            if (a[i] >= current)
                cand = a[i];


            long long key = current + a[i];
            auto it = std::lower_bound(b.begin(), b.end(), key);
            if (it != b.end()) {
                long long candidate2 = *it - a[i];
                if (candidate2 >= current)
                    cand = min(cand, candidate2);
            }


            if (cand == INF) {
                possible = false;
                break;
            }

            current = cand;
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
