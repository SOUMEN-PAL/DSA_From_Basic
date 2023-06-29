/*
    Count only Repeated
MediumAccuracy: 46.52%Submissions: 23K+Points: 4
Sharpen up your programming skills, participate in coding contests & explore high-paying jobs

Given an array arr[] of N positive integers, where elements are consecutive (sorted). Also, there is a single element which is repeating X (any variable) number of times. Now, the task is to find the element which is repeated and number of times it is repeated.
Note: If there's no repeating element, Return {-1,-1}.


Example 1:

Input:
N = 5
arr[] = {1,2,3,3,4}
Output: 3 2
Explanation: In the given array, 3 is 
occuring two times.
Example 2:

Input:
N = 5
arr[] = {2,3,4,5,5}
Output: 5 2
Explanation: In the given array, 5 is 
occuring two times.
Example 3:

Input:
N = 3
arr[] = {1,2,3}
Output: -1 -1
Explanation: In the given array, there's no
repeating element, and thus the given Output.

Your Task:
Complete findRepeating function and return pair of element which is repeated and the number of times it is repeated. The printing is done by the driver code.*/

#include<bits/stdc++.h>
using namespace std;

pair<long, long> findRepeating(int *arr , int n){
    long Repeat_Count = n - (arr[n-1] - arr[0]);
    if(n==0){
        return {0 , 0};
    }
    else if(Repeat_Count<=1){
        return {-1 , -1};
    }
    else{
        long low = 0 , high = n-1 , mid = -1;
        int check = arr[0];
        while(high>=low){
            mid = low + (high - low)/2;
            if(arr[mid] >= mid + check){
                low = mid + 1;
            }
            else{
                high = mid-1;
            }
        }
        pair<long , long>p;
        p.first = arr[mid];
        p.second = Repeat_Count;
        return p;
    }
    return {0 , 0};
}


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,9,9,9,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    pair<long , long> res;

    res = findRepeating(arr , n);
    cout<<res.first<<"  "<<res.second<<endl;
    
    return 0;
}