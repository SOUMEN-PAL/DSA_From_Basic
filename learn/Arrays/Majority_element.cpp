#include<bits/stdc++.h>
using namespace std;

// Naive solution //

int maj_ele(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        int curr = -1;
        for(int j = 0 ; j<n  ;j++){
            if(arr[j]==arr[i]){
                curr++;
            }
        }
        if(curr>n/2){
            return arr[i];
        }
    

    }
    return -1;
    
}

// efficient solution //
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
    int arr[] = {7,1,7,2,7,3,7,4,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maj_ele(arr , n)<<endl;
    cout<<majority(arr , n)<<endl;


    return 0;
}