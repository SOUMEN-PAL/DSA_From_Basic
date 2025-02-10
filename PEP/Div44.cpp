#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ArrayInfo {
    long long T, S;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ArrayInfo> arr(n);
        long long sumS_all = 0;
        for (int i = 0; i < n; i++) {
            long long T = 0, S = 0;
            long long prefix = 0;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                T += x;
                prefix += x;
                S += prefix;
            }
            arr[i] = { T, S };
            sumS_all += S;
        }

        sort
        (
            arr.begin(),
            arr.end(), 
            [](const ArrayInfo& a, const ArrayInfo& b
        ) {
            return a.T > b.T;
            });

        long long extra = 0;
        for (int i = 0; i < n; i++) {
            int weight = n - 1 - i;
            extra += (long long)weight * arr[i].T;
        }

        long long ans = sumS_all + (long long)m * extra;
        cout << ans << "\n";
    }
    return 0;
}
