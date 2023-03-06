#include <bits/stdc++.h>
using namespace std;


// naive approach //


int max_sum(int arr[] , int n){
    int res = arr[0];

    for(int i = 0 ; i<n ; i++){
        int curr = 0;
        for(int j  = i ; j<n ; j++){
            curr = arr[j]+curr;
            res = max(res , curr);
        }
    }
    return res;

}

// efficient solution //
 int mSum(int arr[] , int n){
    int res = arr[0];
    int maxend = arr[0];
    for(int i = 1 ; i<n ; i++ ){
        maxend = max(arr[i] , maxend+arr[i]);
        res = max(res , maxend);
    }
    return res;

 }






int main(){
    int arr[] = {2,3,-8,7,-1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<max_sum(arr , n)<<endl;
    cout<<mSum(arr , n)<<endl;


    return 0;
}