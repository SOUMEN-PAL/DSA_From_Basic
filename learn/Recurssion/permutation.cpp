#include <bits/stdc++.h>
using namespace std;

string ds = "";
void per( string s , int i , int &cnt , int k){
    if(i==s.length()-1){
        cnt++;
        if(cnt == k){
            ds = s;
        }
    }
    else{
        for(int j = i ; j<s.length() ; j++){
            swap(s[i],s[j]);
            per(s , i+1 , cnt , k);
            
        }
    }
}

int main(){
    string s = "123";
    int cnt = 0;
    int k = 3;
    per(s , 0 , cnt , k); 
    cout<<ds<<endl;




    return 0;
}