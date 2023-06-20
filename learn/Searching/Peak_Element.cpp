#include<bits/stdc++.h>
using namespace std;


// naive solution //
int peak_element(int arr[] , int n){
    if(n==1){
        return arr[0];
    }
    else if(arr[0]>arr[1]){return arr[0];}
    else if(arr[n-1]>arr[n+2]){return arr[n];}
    for(int i = 1 ; i<n-1 ; i++){
        if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}

// Efficient solution //
int PeakElement(int arr[] , int n){
    int low = 0 , high = n - 1;

    while(high>=low){
        int mid = (high + low)/2;
        if((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n-1 || arr[mid + 1]<= arr[mid])){
            return arr[mid];
        }
        else if(arr[mid - 1]>=arr[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return -1;
}


int main(){
    int arr[] = {10 , 20 , 30 , 40 , 90 , 80 , 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<peak_element(arr , n)<<endl;
    cout<<PeakElement(arr , n)<<endl;
    return 0;
}