#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(int arr[] , int n){
    stack<int> s;
    vector<int> res;
    s.push(arr[n-1]);
    for(int i = n-1 ; i>=0 ; i--){
        while(s.empty() == false && s.top()<=arr[i]){
            s.pop();
        }

        int ng = s.empty()? -1 : s.top();
        res.push_back(ng);
        s.push(arr[i]);
    }
    reverse(res.begin() , res.end());
    return res;
}

int main(){
    int arr[] = {5,15,10,8,6,12,9,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> res = nextGreater(arr , n);

    for(auto i : res){
        cout<<i<<" ";
    }
    return 0;
}