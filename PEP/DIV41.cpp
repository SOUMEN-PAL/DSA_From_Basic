#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string W;
        cin >> W;
        W.replace(W.size() - 2, 2, "i");
        cout << W << endl;
    }
    return 0;
}