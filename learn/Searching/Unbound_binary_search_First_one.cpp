#include<bits/stdc++.h>
using namespace std;

// code for first occurence of 1 in an infinite binary sorted array //


int firstOccurenceOfOne(int arr[] , int low , int high){
    while(low <= high){
        int mid = (low + high)/2;
        
    }
}




int First_one(int arr[]){
    int l = 0 , h = 1;
    while(arr[h] == 0){
        l = h;
        h = h*2;
    }
    if(arr[h-1]==0){return h;}

    
}





int main(){
    
    return 0;
}