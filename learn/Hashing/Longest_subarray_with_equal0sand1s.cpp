#include<bits/stdc++.h>
using namespace std;


// naive solution //
int longest_1sand0s(int arr[] , int n){
    int res = 0 , count1 = 0 , count0 = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = i ; j<n ; j++){
            if(arr[j] == 0){
                count0++;
            }
            else{
                count1++;
            }
            if(count1 == count0){
                res = max(res , j-i + 1);
            }
        }
        count0 = 0;
        count1 = 0;
    }
    return res;
}

// Efficient soltion for no of subarrays with equal no of zeroes and ones//
int  NumberOFSubarray(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == 0){
            arr[i] = -1; //____+modifying the array to make it look like a zero sum subarray //
        }
    }

    int Pre_sum = 0;
    int count = 0;
    unordered_map<int , int> mp; // for storing the number of places the prfix sum is same representing that the subarray is 0 //
    for(int i = 0 ; i<n ; i++){
        Pre_sum += arr[i];
        if(Pre_sum == 0){
            count++;
        }
        if(mp.find(Pre_sum) != mp.end()){
            count += mp[Pre_sum];
        }
        mp[Pre_sum]++;
    }
    return count;
}

int longestArray(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == 0){
            arr[i] = -1; //____+modifying the array to make it look like a zero sum subarray //
        }
    }
    int curr = 0;
    int res = 0;
    unordered_map<int , int> mp;
    for(int i = 0 ; i<n ; i++){
        curr += arr[i];
        if(curr == 0){
            res = i+1;
        }
        if(mp.find(curr) == mp.end()){
            mp.insert({curr  , i});
        }
        if(mp.find(curr) != mp.end()){
            res = max(res , i - mp[curr]);
        }
    }
    return res;
}

int main(){
    int arr[] = {1,0,1,1,1,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longest_1sand0s(arr , n)<<endl;
    cout<<longestArray(arr , n)<<endl;
    cout<<NumberOFSubarray(arr , n)<<endl;

    return 0;
}