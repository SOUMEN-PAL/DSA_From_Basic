#include<bits/stdc++.h>
using namespace std;

// code for first occurence of 1 in an infinite binary sorted array //


int firstOccurenceOfOne(int arr[] , int low , int high){
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == 0){
            low = mid + 1;
        }
        else{
            if(mid == 0 || arr[mid - 1] != arr[mid]){
                return mid;
            }
            else{
                high = mid - 1;
            }

        }
        
    }
}




int First_one(int arr[]){
    int l = 0 , h = 1;
    while(arr[h] == 0){
        l = h;
        h = h*2;
    }
    if(arr[h-1]==0){return h;}

    return firstOccurenceOfOne(arr , l , h);

    
}





int main(){

    int arr[] = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout<<First_one(arr)<<endl;
    
    return 0;
}