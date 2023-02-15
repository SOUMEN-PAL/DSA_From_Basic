#include <bits/stdc++.h>
using namespace std;
// naive solution //
void left_rotate(int arr[] , int n){
    int temp = arr[0];
    for(int i = 1 ; i<n ; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;



}

void d_rotate(int arr[] , int n , int d){
    for(int i = 0 ; i<d ; i++){
        cout<<i<<endl;
        left_rotate(arr , n);
    }
}

// better solution //

void rotate_arr(int arr[] , int n , int d){
    int temp[d];
    for(int i =0 ; i<d ; i++){
        temp[i] = arr[i];
    }
    for(int i = d ; i<n ; i++){
        arr[i-d] = arr[i];
    }
    for(int i  = 0 ; i<d ; i++){
        arr[n-d+i]= temp[i];
    }





}

// efficient solution //
void rev(int arr[] , int size , int start , int end){
    int low = start , high = end-1;
    while(low<high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}


void eff_rotate(int arr[] , int n , int d){
    rev(arr , n , 0 , d);
    rev(arr , n , d , n);
    rev(arr , n , 0 , n);
    
}






int main(){
    
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    eff_rotate(arr , n , 3);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;





    return 0;
}