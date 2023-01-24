#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string a;
    cin>>a;
    string res;
    int x = a.size();
    for(int i = (x-1) ; i>=0 ; i--){
        res = res + a[i];
    }
    if(a==res){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not a plaindrome"<<endl;
    }

    return 0;
}