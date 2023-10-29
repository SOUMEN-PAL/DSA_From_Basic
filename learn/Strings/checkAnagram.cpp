#include<bits/stdc++.h>
using namespace std;

// TC : O(n!) ans AS : O(n) // 
// Ultra Naive solution //
void permutation(string s , unordered_set<string> & hs , int i = 0){
    if(i == s.length() - 1){
        hs.insert(s);
    }
    for(int j = i ; j<s.length() ; j++){
        swap(s[i] , s[j]);
        permutation(s , hs , i+1);
        swap(s[j] , s[i]);
    }
}

// TC O(nlogn) Naive solution //

bool isAnagram(string s , string t){
    if(s.length() != t.length()){
        return false;
    }
    sort(s.begin() , s.end());
    sort(t.begin() , t.end());
    return (s==t);
}


int main(){
    string s1 = "listen";
    string s2 = "silent";
    unordered_set<string> hs;
    permutation(s1 , hs);
    if(hs.find(s2) != hs.end()){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not found"<<endl;
    }
    return 0;
}