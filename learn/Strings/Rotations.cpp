#include<bits/stdc++.h>
using namespace std;


// Efficirnt sulution using STL functions //
bool areRotations(string str1 , string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}


int main(){
    string s = "ABCD";
    cout<<s.substr(2)<<endl;
    return 0;
}