#include<bits/stdc++.h>
using namespace std;

// longest subarray with goven sum //
// naive solution //
int longest_sub(int arr[] , int n , int sum){
    int res = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        int curr = 0;
        for(int j = i ; j<n ; j++){
            curr += arr[j];
            if(curr == sum){
                res = max(res , j - i + 1);
            }
        }
    }
    return res;
}

int main(){
    int arr[]={5,8,-4,-4,9,-2 , 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    cout<<longest_sub(arr , n , sum)<<endl;
    return 0;
}