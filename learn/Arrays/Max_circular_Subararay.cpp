#include<bits/stdc++.h>
using namespace std;

// naive solution //

int max_sub(int arr[] , int n){
    int res = arr[0];
    for(int i = 0 ; i<n ; i++){
        int curr_sum = arr[i];
        int curr_max = arr[i]; // supossed to be res in max subarray sum naive solution as its always starting for i we always making the value to the supposed start //
        for(int j = 1 ; j<n ; j++){
            int index = (i+j)%n;
            curr_sum +=arr[index];
            curr_max = max(curr_sum , curr_max);
   
        }
        res = max(curr_max , res);
    }
    return res;
}


// efficient solution //
int max_norm(int arr[] , int n){

    // kandane algorithm //
    int res = arr[0];
    int max_sum = arr[0];
    for(int i = 1 ; i<n ; i++){
        max_sum = max(arr[i] , max_sum + arr[i]);
        res = max(res , max_sum);
    }

    return res;
}

int max_circular_sub(int arr[] , int n){
    int max_sum = max_norm(arr , n);
    if(max_sum<0){
        return max_sum;
    }

    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum +=arr[i];
        arr[i] = -arr[i];
    }
    int max_circ = sum + max_norm(arr,n);

    return max(max_sum , max_circ);
}

// eff done //



int main(){
    int arr[] = {5 , 10 , -2 , 59 , -10 , };
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout<<max_sub(arr , n)<<endl;
    cout<<max_circular_sub(arr , n)<<endl;

    
    return 0;
}