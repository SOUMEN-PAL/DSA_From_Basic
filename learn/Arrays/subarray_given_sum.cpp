#include<bits/stdc++.h>
using namespace std;

// naive_soluton //
bool subarray_with_given_sum(int arr[] , int n  , int sum){
    for(int i = 0 ; i<n ; i++){
        int curr = 0;
        for(int j = i ; j<n  ; j++){
            curr+=arr[j];
            if(curr==sum){
                return true;
            }
        }
    }
    return false;
}


// Efficiet solution //



int main(){
    int arr[] = {1,4,20,3,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 33;

    bool ans = subarray_with_given_sum(arr , n , sum);
    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
 
    

    

    
    return 0;
}