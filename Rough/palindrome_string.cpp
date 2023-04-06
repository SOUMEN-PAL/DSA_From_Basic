#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string &str , int start , int end){
    if(start>=end){
        return true;
    }

    return (str[start]==str[end] && ispalindrome( str , start+1 , end-1));
}


int main(){
    string s = "lol";
    int st = 0 , e = s.length()-1;
    if(ispalindrome(s , st , e)){
        cout<<s<<" is a plindrome"<<endl;
    }
    else{
        cout<<"not a palindrome"<<endl;
    }

    return 0;
}