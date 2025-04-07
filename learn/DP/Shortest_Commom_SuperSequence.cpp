#include <bits/stdc++.h>
using namespace std;

string shortestSupersequence(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    
    // Create dp table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Fill dp table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    string result = "";
    int i = n, j = m;
    
    while(i > 0 && j > 0) {
        if(str1[i-1] == str2[j-1]) {
            result = str1[i-1] + result;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            result = str1[i-1] + result;
            i--;
        }
        else {
            result = str2[j-1] + result;
            j--;
        }
    }
    
    // Add remaining characters from str1
    while(i > 0) {
        result = str1[i-1] + result;
        i--;
    }
    
    // Add remaining characters from str2
    while(j > 0) {
        result = str2[j-1] + result;
        j--;
    }
    cout<<result<<endl;
    return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s = "abac";
  string ss = "cab";

  string res = shortestSupersequence(s, ss);
  cout<<res<<endl;
  return 0;
}
