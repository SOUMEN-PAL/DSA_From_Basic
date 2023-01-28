#include <bits/stdc++.h>
using namespace std;

void subset(string s , string a = "" , int i = 0){
    
    if(i==s.size()){
        cout<<a<<" ";
        return;
    }

    subset(s , a , i+1);
    subset(s , a+s[i], i+1);


}



int main(){
    subset("abc");



    return 0;
}