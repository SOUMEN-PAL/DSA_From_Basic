#include <bits/stdc++.h>
using namespace std;
map<int,string> help(){
    map<int,string> phone;
    phone[2] = "ABC";
    phone[3] = "DEF";
    phone[4] = "GHI";
    phone[5] = "JKL";    
    phone[6] = "MNO";
    phone[7] = "PQRS";
    phone[8] = "TUV";
    phone[9] = "WXYZ";

    return phone;
}

void pos(string s , vector<string> &ans , int i=0 ){
    if(i==s.length()){
        ans.push_back(s);
        return;
    }
    for(int j =i ; j<s.length() ; j++){
        swap(s[i],s[j]);
        pos(s , ans , i+1);
        swap(s[i],s[j]);
    }
}

vector<string> poss(int a[] , int n){
    vector<string> res;
    map<int,string> helper = help();
    for(int i = 0 ; i<=n ; i++){
        int mm = a[i];

        string str = helper[mm];
        pos(str , res);
    }
    return res;

    
}

int main(){
    int arr[] = {3 , 4 , 5};
    int n = 3;
    vector <string> res = poss(arr  , n);
    for(int i = 0 ; i<res.size() ; i++){
        cout<<res[i]<<" ";
    }

    return 0;
}