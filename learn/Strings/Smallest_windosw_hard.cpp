#include<bits/stdc++.h>
using namespace std;


// Naive approach
string smallestWindow (string s, string p)
    {
        int n = s.length();
        int m = p.length();
        unordered_map<char, int> p_map;
        unordered_map<char, int> s_map;
        for (int i = 0; i < m; i++) {
            p_map[p[i]]++;
        }
    
        int len = p_map.size();
        int match_len = 0;
        string res = "-1";
        int res_len = INT_MAX;
    
        int l = 0, r = 0 , i , j;
        while (r < n) {
            s_map[s[r]]++;
            if (p_map.find(s[r]) != p_map.end() && p_map[s[r]] == s_map[s[r]]) {
                match_len++;
            }
    
            while (match_len == len) {
                int le = r - l + 1;
    
                
                if (le < res_len && l < n) {
                    i = l;
                    j = r;
        
                    
                    res_len = le;
                }
    
                s_map[s[l]]--;
                if (p_map.find(s[l]) != p_map.end() && p_map[s[l]] > s_map[s[l]]) {
                    match_len--;
                }
                l++;
            }
            r++;
        }
        res = s.substr(i, j - i + 1);
        
        return res;
    }

// Efficient approach

string smallestWindoweff (string s, string p)
{
    int n = s.length();
    int m = p.length();
    
    if(m > n || n == 0 || m == 0){
        return "-1";
    }
    
    int p_map[256] = {0};
    for(int i = 0 ; i<m ; i++){
        p_map[p[i]]++;
    }
    
    int total_len = 0;
    
    for(int i = 0 ; i<256 ; i++){
        if(p_map[i]>0){
            total_len++;
        }
    }
    
    int match_len = 0;
    string res = "-1";
    int res_len = INT_MAX;
    int l = 0 , r = 0 , i , j;
    
    while(r<n){
        p_map[s[r]]--;
        
        if(p_map[s[r]] == 0){
            match_len++;
        }
        
        while(match_len == total_len){
            int le = r - l + 1;
            if(le<res_len){
                i = l;
                j = r;
                res_len = le;
            }
            
            p_map[s[l]]++;
            
            if(p_map[s[l]]>0){
                match_len--;
            }
            l++;
        }
        r++;
    }
    
    return res_len == INT_MAX?"-1":s.substr(i , j - i + 1);
    
}

int main(){
    string s , p;
    cin>>s>>p;
    cout<<smallestWindow(s , p)<<endl;
    cout<<smallestWindoweff(s , p)<<endl;
    
    return 0;
}