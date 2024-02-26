#include<bits/stdc++.h>
using namespace std;
	    void helper(string s , vector<string> &res , string a = "" , int i = 0){
	        if(i == s.size()){
	            res.push_back(a);
	        }
	        
	        helper(s  , res , a , i+1);
	        helper(s , res , a+s[i] , i+1);
	    }
int main(){
    string s = "abc";
    vector<string> res;
    helper(s , res);
    for(auto i : res){
        cout<<i<<" ";
    }
    return 0;
}