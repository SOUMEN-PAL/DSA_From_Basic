#include<bits/stdc++.h>
using namespace std;


vector<int> getMinAtPop(int arr[] , int n){
    stack<int> s;
    vector<int> res;
    s.push(arr[0]);
    for(int i = 0 ; i<n ; i++){
        if(arr[i]<s.top()){
            s.push(arr[i]);
        }
        else{
            s.push(s.top());
        }
    }

    while(s.empty() == false){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}


int main(){
    int arr[] = {1 , 2 , 3,0 ,1 , 13 , 4 , 1, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> res = getMinAtPop(arr , n);
    for(auto i : res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}