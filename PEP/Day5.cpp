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

int findOddInPair(int arr[] , int n){
    int low = 0 , high = n-1;
    while(high>=low){
        int mid = low + (high - low)/2;
        if((mid  == 0 || arr[mid] != arr[mid-1]) && (mid == n-1 || arr[mid] != arr[mid + 1])){
            return mid;
        }
        if(mid % 2 == 0){
            if(mid + 1 < n && arr[mid] == arr[mid + 1]){
                low  = mid + 2;
            }
            else{
                high = mid - 1;
            }
        }
        else{
            if(mid-1 >=0 && arr[mid] == arr[mid - 1]){
                low = mid + 1;
            }
            else{
                high = mid - 2;
            }
        }
    }
    return -1;
}


// Perfect square

int leastNearest(int n){
    int low = 0 , high = n , res = -1;
    while(high>=low){
        int mid = (high + low)/2;
        long long int sqM = mid * mid;
        if(sqM == n){
            return mid;
        }
        else if(sqM > n){
            high = mid -1;
        }
        else{
            
            low = mid + 1;
            res = mid;
        }
    }
    return res;
}


int main(){
    int arr[] = {3,3,2,2,1,1,7,9,9,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    

    cout<<leastNearest(0);
    
    return 0;
}