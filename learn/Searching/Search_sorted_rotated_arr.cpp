#include<bits/stdc++.h>

using namespace std;


int Search_Rotated(int arr[] , int n , int x){

    int low = 0 , high = n-1;
    while(high>=low){
        int mid = (high + low)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[low]<=arr[mid]){
            if(x<arr[mid] && x>=arr[low]){
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
        }
        else{
            if(x>arr[mid] && x<=arr[high]){
                low = mid + 1;
            }
            else{
                high = mid + 1;
            }
        }
    }
    return -1;


}


int main(){

    int arr[] = {7,8,9,1,2,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 8;
    cout<<Search_Rotated(arr , n , x)<<endl;

    return 0;
}






