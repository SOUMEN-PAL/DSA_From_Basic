#include<bits/stdc++.h>
using namespace std;

void countin_sort(int arr[] , int n , int k){
    int count[10] = {0} , solArray[n];
    for(int i = 0 ; i<n ; i++){
        count[(arr[i]/k)%10]++;
    }
    for(int i = 1 ; i<10 ; i++){
        count[i] = count[i]+count[i-1];
    }
    for(int i = n-1 ; i>=0 ; i--){
        solArray[count[(arr[i]/k)%10]-1] = arr[i];
        count[(arr[i]/k)%10]--;
    }
    for(int i = 0 ; i<n ; i++){
        arr[i] = solArray[i];
    }
}

// radix sort //
// subnet of of counting sort //
void radix_sort(int arr[] , int n){
    int maxValue = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        maxValue = max(maxValue , arr[i]);
    }
    for(int i = 1 ; maxValue/i >0 ; i = i*10){
        countin_sort(arr , n , i);
    }
}



int main(){
    int arr[] = {319 , 212 , 6 , 8,  100 , 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr , n);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}