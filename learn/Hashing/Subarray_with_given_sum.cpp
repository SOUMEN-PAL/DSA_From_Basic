#include<bits/stdc++.h>
using namespace std;


// this efficient solution is for an array containig all integers //
bool SubarrayWithGivenSum(int arr[] , int n , int sum){
    int curr_sum = 0;
    unordered_set<int> s;
    for(int i = 0 ; i<n ; i++){
        curr_sum += arr[i];
        if(curr_sum == sum){
            return true;
        }
        if(s.find(curr_sum - sum) != s.end()){
            return true;
        }
        s.insert(curr_sum);
    }
    return false;
}

int main(){
    int arr[] = {1,4,5,-20,10 , -10};
    int n =sizeof(arr)/sizeof(arr[0]);
    int sum = -20;
    cout<<SubarrayWithGivenSum(arr , n , sum);
    return 0;
}