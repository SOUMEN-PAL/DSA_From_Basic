#include<bits/stdc++.h>
using namespace std;


// Naive solution //
void countSort(int arr[] , int n , int k){
    int count[k] = {0};
    for(int i = 0 ; i<n ; i++){
        count[arr[i]]++;
    }

    int index = 0;
    for(int i = 0 ; i<k ; i++){
        for(int j = 0 ; j<count[i] ; j++){
            arr[index] = i;
            index++;
        }
    } 
}

// Efficient Solution //
void Count_Sort(int arr[] , int n , int k){
    int count[k] = {0};
    for(int i = 0 ; i<n ; i++){
        count[arr[i]]++;
    }
    for(int i = 1 ; i<k ; i++){
        count[i] = count[i] + count[i-1];
    }
    int solutionArray[n];
    for(int i = n-1 ; i>=0 ; i--){
        solutionArray[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0; i<n ; i++){
        arr[i] = solutionArray[i];
    }
}


int main(){
    int arr[] = {1,4,4,2,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    Count_Sort(arr , n , k);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}