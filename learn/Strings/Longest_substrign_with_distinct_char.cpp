#include<bits/stdc++.h>
using namespace std;

// Naive solution //
bool isDistinct(string s, int i, int j) {
    vector<bool> visited(256);
    for (int k = i; k <= j; k++) {
        if (visited[s[k]] == true) {
            return false;
        }
        visited[s[k]] = true;
    }
    return true;
}

int longest_distinct(string s) {
    int n = s.length();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isDistinct(s, i, j)) {
                res = max(res, j - i + 1);
            }
        }

    }
    return res;
}

int main() {

    return 0;
}