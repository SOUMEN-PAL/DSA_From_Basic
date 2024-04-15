#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, q;
        cin >> k >> q;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        while (q--) {
            int n;
            cin >> n;
            int l = 1, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (a[upper_bound(a.begin(), a.end(), mid) - a.begin() - 1] <= mid) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            cout << n - l + 1 << endl;
        }
    }
    return 0;
}