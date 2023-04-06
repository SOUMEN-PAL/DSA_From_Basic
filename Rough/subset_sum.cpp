#include<bits/stdc++.h>
using namespace std;

int subset_sum(int arr[] , int n , int sum){
    if(n==0){
        if(sum==0){
            return 1;

        }
        else{
            return 0;
        }
    }

    return subset_sum(arr , n-1 , sum) + subset_sum(arr  , n-1 , sum-arr[n-1]);
}


int main(){

    int arr[] = {30 , 10 , 20};
    int n = sizeof(arr)/sizeof(arr[0]) ;
    int sum = 30;
    cout<<subset_sum(arr , n , sum)<<endl;
    
    return 0;
}