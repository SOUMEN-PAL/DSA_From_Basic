#include<bits/stdc++.h>
using namespace std;

string deleteConsecutive2(string str){
    stack<char> s;
    for(int i = 0 ; i<str.length() ; i++){
        if(s.empty() == true){
            s.push(str[i]);
        }
        else{
            if(s.top() == str[i]){
                s.pop();
            }
            else{
                s.push(str[i]);
            }
        }
    }
    string ans = "";
    while(!s.empty()){
        ans = s.top() + ans;
        s.pop();
    }
    return ans;
}


int main(){
    string s = "aaabbaaccd";
    cout<<deleteConsecutive2(s)<<endl;
    return 0;
}