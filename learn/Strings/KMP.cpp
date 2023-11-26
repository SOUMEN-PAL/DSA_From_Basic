#include<bits/stdc++.h>
using namespace std;


// Naive Proper Prefix Suffix TC : O(n^3) //
int ProperPrefixSuffix(string s , int n){
    for(int len = n-1 ; len>0 ; len--){
        bool flag = true;
        for(int i = 0 ; i<len ; i++){
            if(s[i] != s[n - len + i]){
                flag = false;
                break;
            }
        }
        if(flag){
            return len;
        }
    }
    return 0;
}

void fillProperPrefixSuffix(string s , int n , int lps[]){
    for(int i = 0 ; i<n ; i++){
        lps[i] = ProperPrefixSuffix(s , i+1);
    }
} 


// Efficient Proper Prefix Suffix TC : O(n) //
// void fillLps(string s , int arr[]){
//     int n = s.length() , len = 0;
//     int i = 1;
    
// }


int main(){


    string s = "abbabb";
    int arr[s.length()];
    fillProperPrefixSuffix(s , s.length() , arr);
    for(int i = 0 ; i<s.length() ; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}