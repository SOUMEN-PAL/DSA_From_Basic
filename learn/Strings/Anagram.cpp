#include<bits/stdc++.h>
using namespace std;


// Naive Solution //
bool isAnagram(string s , string p , int i){
    map<char , int> count;
    for(int j = 0 ; j<p.length() ; j++){
        count[s[i+j]]++;
        count[p[j]]--;
    }
    for(int j = 0 ; j<256 ; j++){
        if(count[j]!=0){
            return false;
        }
    }
    return true;
}


bool Aanagram_search(string s , string p){
    int n = s.length();
    int m = p.length();
    for(int i = 0 ; i<n-m ; i++){
        if(isAnagram(s , p , i)){
            return true;
        }
    }
    return false;
}

// Effiicient Solution //

bool areSame(int count[] , int count1[]){
    for(int i = 0 ; i<256 ; i++){
        if(count[i]!=count1[i]){
            return false;
        }
    }
    return true;
}

vector<int> isPresent(string txt , string pat){
    int n = txt.length();
    int m = pat.length();
    int count[256] = {0};
    int count1[256] = {0};
    vector<int> res;
    for(int i = 0 ; i<m ; i++){
        count[txt[i]]++;
        count1[pat[i]]++;
    }

    for(int i = m ; i<n ; i++){
        if(areSame(count , count1)){
            res.push_back(i-m);
        
        }

        count[txt[i]]++;
        count[txt[i-m]]--;
    }

    if(areSame(count , count1)){
        res.push_back(n-m);
    }

    return res;
}


int main(){

    string s = "abab";
    string p = "ab";
    cout<<Aanagram_search(s , p)<<endl;
    // cout<<isPresent(s , p)<<endl;

    vector<int> res = isPresent(s , p);
    for(auto i : res){
        cout<<i<<endl;
    }
    
    return 0;
}