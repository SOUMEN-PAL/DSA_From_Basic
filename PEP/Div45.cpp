#include <bits/stdc++.h>
using namespace std;

string constructPathNM(int n, int m, int k) {
    int finalVal = n - m;
    string res;
    res.reserve(n + m);
    int remain0 = n;
    int remain1 = m;
    int cur = 0;


    if (k > remain0) return "";
    for (int i = 0; i < k; i++) {
        res.push_back('0');
    }
    remain0 -= k;
    cur = k;


    while (remain0 + remain1 > 0) {
        if (cur == k) {
            if (remain1 <= 0) return "";
            res.push_back('1');
            remain1--;
            cur--;
        }
        else if (cur == 0) {
            if (remain0 <= 0) return "";
            res.push_back('0');
            remain0--;
            cur++;
        }
        else {
            if (cur > finalVal) {
                if (remain1 > 0) {
                    res.push_back('1');
                    remain1--;
                    cur--;
                }
                else if (remain0 > 0) {
                    res.push_back('0');
                    remain0--;
                    cur++;
                }
                else return "";
            }
            else if (cur < finalVal) {
                if (remain0 > 0) {
                    res.push_back('0');
                    remain0--;
                    cur++;
                }
                else if (remain1 > 0) {
                    res.push_back('1');
                    remain1--;
                    cur--;
                }
                else return "";
            }
            else {
                if (remain1 > 0) {
                    res.push_back('1');
                    remain1--;
                    cur--;
                }
                else if (remain0 > 0) {
                    res.push_back('0');
                    remain0--;
                    cur++;
                }
                else return "";
            }
        }
    }
    if (cur != finalVal) return "";
    return res;
}

string constructPathMN(int n, int m, int k) {
    int finalVal = m - n;
    string res;
    res.reserve(n + m);
    int remainPlus = m;
    int remainMinus = n;
    int cur = 0;

    if (k > remainPlus) return "";
    for (int i = 0; i < k; i++) {
        res.push_back('1');
    }
    remainPlus -= k;
    cur = k;

    while (remainPlus + remainMinus > 0) {
        if (cur == k) {
            if (remainMinus <= 0) return "";
            res.push_back('0');
            remainMinus--;
            cur--;
        }
        else if (cur == 0) {
            if (remainPlus <= 0) return "";
            res.push_back('1');
            remainPlus--;
            cur++;
        }
        else {
            if (cur > finalVal) {
                if (remainMinus > 0) {
                    res.push_back('0');
                    remainMinus--;
                    cur--;
                }
                else if (remainPlus > 0) {
                    res.push_back('1');
                    remainPlus--;
                    cur++;
                }
                else return "";
            }
            else if (cur < finalVal) {
                if (remainPlus > 0) {
                    res.push_back('1');
                    remainPlus--;
                    cur++;
                }
                else if (remainMinus > 0) {
                    res.push_back('0');
                    remainMinus--;
                    cur--;
                }
                else return "";
            }
            else {
                if (remainMinus > 0) {
                    res.push_back('0');
                    remainMinus--;
                    cur--;
                }
                else if (remainPlus > 0) {
                    res.push_back('1');
                    remainPlus--;
                    cur++;
                }
                else return "";
            }
        }
    }
    if (cur != finalVal) return "";
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string ans;

        if (n >= m) {
            if (k < (n - m) || k > n) {
                cout << -1 << "\n";
                continue;
            }
            ans = constructPathNM(n, m, k);
        }
        else {
            if (k < (m - n) || k > m) {
                cout << -1 << "\n";
                continue;
            }
            ans = constructPathMN(n, m, k);
        }
        if (ans == "") cout << -1 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}
