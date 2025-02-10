#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 200000;

vector<int> spf(MAX + 1, 0);

void sieve() {
    int N = MAX;
    for (int i = 1; i <= N; i++)
        spf[i] = i;
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> fac;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            cnt++;
            x /= p;
        }
        fac.push_back({ p,cnt });
    }
    return fac;
}

ll encodePair(int p, int q) {
    return ((ll)p << 20) | q;
}

ll comb2(ll x) { return (x * (x - 1)) / 2; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        unordered_map<int, ll> A;
        unordered_map<int, ll> B;
        unordered_map<ll, ll> C;

        for (int x = 2; x <= n; x++) {
            if (freq[x] == 0) continue;
            vector<pair<int, int>> fac = factorize(x);
            if (fac.size() == 1) {
                int p = fac[0].first, e = fac[0].second;
                if (e == 1) {
                    A[p] += freq[x];
                }
                else if (e == 2) {
                    B[p] += freq[x];
                }
            }
            else if (fac.size() == 2) {
                if (fac[0].second == 1 && fac[1].second == 1) {
                    int p = fac[0].first, q = fac[1].first;
                    if (p > q) swap(p, q);
                    ll key = encodePair(p, q);
                    C[key] += freq[x];
                }
            }
        }

        ll total = 0;

        ll sumA = 0, sumA2 = 0;
        for (auto& it : A) {
            sumA += it.second;
            sumA2 += it.second * it.second;
        }
        total += (sumA * sumA - sumA2) / 2;

        for (auto& it : B) {
            int p = it.first;
            if (A.count(p))
                total += A[p] * it.second;
        }

        for (auto& it : C) {
            ll key = it.first;
            int p = key >> 20;
            int q = key & ((1 << 20) - 1);
            ll cnt = it.second;
            if (A.count(p)) total += A[p] * cnt;
            if (A.count(q)) total += A[q] * cnt;
        }

        for (auto& it : B) {
            ll cnt = it.second;
            total += comb2(cnt);
        }

        for (auto& it : C) {
            ll cnt = it.second;
            total += comb2(cnt);
        }

        ll diag = 0;
        for (auto& it : B) diag += it.second;
        for (auto& it : C) diag += it.second;

        total += diag;

        cout << total << "\n";
    }

    return 0;
}
