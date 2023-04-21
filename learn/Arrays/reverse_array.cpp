#include <bits/stdc++.h>
using namespace std;

// my solution //

void rev(int arr[] , int n){
    int m=n-1;
    for(int i = 0 ; i<n/2 ; i++){
        swap(arr[m],arr[i]);
        m=m-1;
    }

    for(int j = 0 ; j<n ; j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}


//naive solution //

void rev_arr(int arr[],int n){
    int low = 0 , high = n-1;

    while(low<high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;


        low++;
        high--;
    }
    for(int j = 0 ; j<n ; j++){
        cout<<arr[j]<<" ";
    }

    cout<<endl;




}



int main(){
    int arr[]={1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    rev(arr,n);
    rev_arr(arr,n);

    
    return 0;
}

/*

5 4 3 2 1--> reversed the array 
1 2 3 4 5--> again called it is reversed

as array is alredy is a direct acess to the memory
and the changes will effect directly.

*/