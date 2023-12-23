#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string s, string p) {
    int n = s.length();
    int m = p.length();

    if (n < m) {
        return "-1";
    }

    unordered_map<char, int> s_map;
    unordered_map<char, int> p_map;

    for (int i = 0; i < m; i++) {
        p_map[p[i]]++; // Initialize the values of the pattern
    }

    int curr_len = 0;
    string res = "-1";
    int res_len = INT_MAX;
    int l = 0, r = 0;

    while (r < n) {
        s_map[s[r]]++;

        if (p_map.find(s[r]) != p_map.end() && p_map[s[r]] == s_map[s[r]]) {
            curr_len++;
        }

        while (curr_len == p_map.size()) {
            if (r - l + 1 < res_len) {
                res = s.substr(l, r - l + 1);
                res_len = r - l + 1;
            }
            s_map[s[l]]--;

            if (p_map.find(s[l]) != p_map.end() && p_map[s[l]] == s_map[s[l]]) {
                curr_len--;
            }
            l++;
        }
        r++;
    }

    if (res_len == INT_MAX) {
        return "-1";
    }
    return res;
}


int main(){
    string s = "timetopractice";
    string p = "tttoooccoc";
    cout<<smallestWindow(s , p)<<endl;
    cout<<s.substr(0, 3+1);
    return 0;
}