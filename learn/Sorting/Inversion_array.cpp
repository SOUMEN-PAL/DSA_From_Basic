#include<bits/stdc++.h>
using namespace std;

// naive solution //
int Count_Inversion(int arr[] , int n){
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}



//___________Efficient Solution_____________//
int mergeCount(int arr[] , int low , int mid , int high)
{
    int n1 = mid-low+1 , n2 = high - mid;
    int leftArray[n1] , rightArray[n2];
    for(int i = 0 ; i<n1 ; i++)
    {
        leftArray[i] = arr[low + i];
    }
    for(int i = 0 ; i<n2 ; i++)
    {
        rightArray[i] = arr[mid + 1 + i];
    }
    
}


int main(){
    int arr[] = {2,4,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Count_Inversion(arr , n );
    return 0;
}