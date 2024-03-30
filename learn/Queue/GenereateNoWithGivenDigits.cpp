#include<bits/stdc++.h>
using namespace std;

string GenerateNo(int n){
    string res = "";
    queue<string> q;
    q.push("5");
    q.push("6");
    for(int count = 0 ; count<n ; count++){
        string curr = q.front();
        res = res + curr;
        q.pop();
        q.push(curr + "5");
        q.push(curr + "6");
    }
    return res;
}

int main(){
    cout<<GenerateNo(40)<<endl;
    return 0;
}