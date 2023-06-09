#include <bits/stdc++.h>
using namespace std;

void per( string s , int i = 0){
    if(i==s.length()-1){
        cout<<s<<" ";
    }
    else{
        for(int j = i ; j<s.length() ; j++){
            swap(s[i],s[j]);
            per(s , i+1);
            swap(s[i],s[j]);

        }
    }

    
}

int main(){
    per("AB"); 




    return 0;
}