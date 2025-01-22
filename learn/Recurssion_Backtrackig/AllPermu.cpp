#include<bits/stdc++.h>
using namespace std;


bool isSafe(string s , int l , int i , int r){
    if(l != 0 && s[l-1] == 'A' && s[i] == 'B'){
        return false;
    }
    if(r==(l+1) && s[i]=='A' && s[l]=='B')
        return false;
    return true;
}

void permu(string s , int i){
    if(i == s.length()){
        cout<<s<<" ";
    }

    for(int l = i ; l<s.length() ; l++){
        if(isSafe(s , l , i , s.length())){
            swap(s[i] , s[l]);
            permu(s , i+1);
            swap(s[i] , s[l]);
        }
        
    }
}


int main(){
    string s;
    cout<<"Enter the String: ";
    cin>>s;
    permu(s , 0);
    cout<<endl;
    return 0;
}