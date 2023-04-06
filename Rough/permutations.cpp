#include<bits/stdc++.h>
using namespace std;

void permu(string s , int i = 0){
    if(i==s.length()-1){
        cout<<s<<" ";
    }

    else{
        for(int j = i  ; j<s.length() ; j++){
            swap(s[i],s[j]);
            permu(s , i+1);
            swap(s[i],s[j]);
        }
    }
}

int main(){
    permu("ABC");
    return 0;
}