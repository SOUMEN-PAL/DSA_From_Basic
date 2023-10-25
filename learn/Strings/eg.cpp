#include<bits/stdc++.h>
using namespace std;

void print(string s){
    int count[26] = {0}; // Frequnecy storing array //
    for(int i = 0 ; i<s.length() ; i++){
        count[s[i] - 'a']++;
    }
    for(int i = 0 ; i<26 ; i++){
        if(count[i]>0){
            cout<<char(i +'a')<<" "<<count[i]<<endl;
        }
    }
}


int main(){
    string s = "geeksforgeeks";
    print(s);
    return 0;
}