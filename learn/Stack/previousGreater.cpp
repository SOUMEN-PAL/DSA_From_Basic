#include<bits/stdc++.h>
using namespace std;

void previousGreater(int arr[] , int n){
    stack<int> s;
    s.push(arr[0]);
    for(int i = 0 ; i<n ; i++){
        while(s.empty() == false && s.top() <= arr[i]){
            s.pop();
        }

        int p = s.empty()?-1 : s.top();
        cout<<p<<" ";
        s.push(arr[i]);
    }
}

int main(){
    int arr[] = {13 , 15 , 12 , 14 , 16 , 8 , 6 , 4 ,10 , 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    previousGreater(arr , n);
    return 0;
}