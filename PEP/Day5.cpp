#include<bits/stdc++.h>
using namespace std;

// Naive solution Search in sorted rotated // 
int searchRotatedSorted(int arr[] , int n , int target){
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}



// Efficient solution 

int searchEfficient(int arr[] , int n , int x){
    int low = 0 , high = n-1;
    while(high >= low){
        int mid = low + (high - low)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[low] <= arr[mid]){
            if(x<arr[mid] && x>=arr[low]){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(x>arr[mid] && x<=arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

    }
    return -1;
}


int main(){
    int arr[] = {7,8,9,1,2,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<searchEfficient(arr , n , 8);
    
    return 0;
}