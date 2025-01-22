#include <bits/stdc++.h>
using namespace std;

int countMatches(const string &code, const string &attempt) {
    int count = 0;
    for (int i = 0; i < code.size(); ++i) {
        if (code[i] == attempt[i]) {
            ++count;
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> attempts(m);
    
    for (int i = 0; i < m; ++i) {
        cin >> attempts[i].first >> attempts[i].second;
    }
    
    int validCodes = 0;
    int totalCodes = 1 << n-1; 
    
    for (int i = 0; i < totalCodes; ++i) {
        string code;
        for (int j = 0; j < n; ++j) {
            code += (i & (1 << j)) ? '1' : '0';
        }
        
        bool isValid = true;
        for (const auto &attempt : attempts) {
            if (countMatches(code, attempt.first) != attempt.second) {
                isValid = false;
                break;
            }
        }
        
        if (isValid) {
            ++validCodes;
        }
    }
    
    cout << validCodes << endl;
    return 0;
}