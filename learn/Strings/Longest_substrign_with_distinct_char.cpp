#include<bits/stdc++.h>
using namespace std;

// BruteForce solution //
// Time complexity: O(n^3)  Space complexity: O(1) //
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
        for (int j = i; j < n; j++) {
            if (isDistinct(s, i, j)) {
                res = max(res, j - i + 1);
            }
        }

    }
    return res;
}

// Naive solution //
// Time complexity: O(n^2)  Space complexity: O(1) //

int eff_longest_substring(string s){
    int n = s.length(); 
    int res = 0;
    for(int i = 0; i < n; i++){
        vector<bool> visited(256);
        for(int j = i; j < n; j++){
            if(visited[s[j]] == true){
                break;
            }
            else{
                res = max(res , j - i  + 1);
                visited[s[j]] = true;
            }
        }
    }
    return res;
    
}


int main() {
    string s = "geekeek";
    cout << longest_distinct(s) << endl;
    cout << eff_longest_substring(s) << endl;

    return 0;
}