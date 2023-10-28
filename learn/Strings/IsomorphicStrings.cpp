#include<bits/stdc++.h>
using namespace std;

bool areIsomorphic(string str1, string str2)
{
    
    int n = str1.length();
    int m = str2.length();
    if(n != m){
        return false;
    }
    unordered_map<char , char> mp1;
    unordered_map<char , char> mp2;
    int i = 0;
    for(int i = 0 ; i<n ; i++){
        if(mp1.find(str1[i]) == mp1.end() && mp2.find(str2[i]) == mp2.end()){
            mp1[str1[i]] = str2[i];
            mp2[str2[i]] = str1[i];
        }
        if(mp1.find(str1[i]) != mp1.end()){
            if(mp1[str1[i]] != str2[i]){
                return false;
            }
        }
        if(mp2.find(str2[i]) != mp2.end()){
            if(mp2[str2[i]] != str1[i]){
                return false;
            }
        }
    }
    return true;
}


int main(){
    string str1 = "xxy";
    string str2 = "aab";
    cout<<areIsomorphic(str1 , str2);
    
    return 0;
}