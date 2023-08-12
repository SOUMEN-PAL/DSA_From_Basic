#include<bits/stdc++.h>
using namespace std;

// naive solution for Partition //
void naivePartition(int arr[] , int l , int h , int p)
{
    int n = (h-l+1) , index = 0;
    int temp[n];
    for(int i = l ; i<=h ; i++)\
    {
        if(arr[i]<=arr[p])
        {
            temp[index++] = arr[i];
        }
    }
    for(int i = 0 ; i<=h ; i++)
    {
        if(arr[i]>arr[p])
        {
            temp[index++] = arr[i];
        }
    }
    for(int i = l ; i<=h ; i++)
    {
        arr[i] = temp[i-l];
    }
    
}




int main(){

    int arr[] = {5,13,6,9,12,11,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int p = 5;
    naivePartition(arr , 0 , n-1 , 6);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}