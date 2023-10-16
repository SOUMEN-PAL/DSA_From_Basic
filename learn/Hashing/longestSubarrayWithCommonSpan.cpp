#include<bits/stdc++.h>
using namespace std;

// Naive Solution //
int longestCommonSubarray(int arr1[] , int arr2[] , int n){
    int sum1 , sum2 , res = 0;
    for(int i = 0 ; i<n ; i++){
        sum1 = 0;
        sum2 = 0;
        for(int j = i ; j<n ; j++){
            sum1 += arr1[j];
            sum2 += arr2[j];
            if(sum1 == sum2)
            {
                res = max(res , j-i + 1);
            }
        }
    }
    return res;
}

// Efficient Solution //
int Longest_Common_Subarray(int arr[] , int brr[] , int n){
    int temp[n];
    for(int i = 0 ; i<n ; i++){
        temp[i] = arr[i] - brr[i];
    }

    int res = 0;
    int curr = 0;
    unordered_map<int , int> mp;
    for(int i = 0 ; i<n ; i++){
        curr += temp[i];
        if(curr == 0){
            res = i+1;
        }
        if(mp.find(curr) == mp.end()){
            mp.insert({curr , i});
        }
        if(mp.find(curr) != mp.end()){
            res = max(res , i - mp[curr]);
        }
    }
    return res;
}

int main(){
    int Array1[] = {0,1,0,0,0,0};
    int Array2[] = {1,0,1,0,0,1};
    int n = sizeof(Array1)/sizeof(Array1[0]);
    cout<<longestCommonSubarray(Array1 , Array2 , n)<<endl;
    cout<<Longest_Common_Subarray(Array1 , Array2 , n)<<endl;
    return 0;
}