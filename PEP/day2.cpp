#include<bits/stdc++.h>
using namespace std;

int majority(int arr[] , int n){
    int res = 0  , c = 1;
    for(int i = 1 ; i<n ; i++){
        if(arr[res]==arr[i]){
            c++;
        }
        else{
            c--;
        }
        if(c==0){
            c=1;
            res = i;
        }
    }

    int curr = 0;

    for(int i = 0 ; i<n ; i++){
        if(arr[i]==arr[res]){
            curr++;
        }
    }

    if(curr>n/2){
        return arr[res];
    }
    else{
        return -1;
    }
}



int main(){
    int arr[] = {1,2,1,1,1,1,4,5,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<majority(arr , n);
    return 0;
}