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
void fillLps(string str , int n , int lps[]){
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i<n){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len - 1];
            }
        }
    }
}



int main(){


    string s = "abacabad";
    int arr[s.length()];
    fillProperPrefixSuffix(s , s.length() , arr);
    for(int i = 0 ; i<s.length() ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int arr1[s.length()];
    fillLps(s , s.length() , arr1);
    for(int i = 0 ; i<s.length() ; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}