#include<bits/stdc++.h>
using namespace std;


//Step 1 Build a max Heap;
void maxHeapify(int arr[] , int n , int i){
    int largest = i , left = 2*i + 1 , right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n  && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i] , arr[largest]);
        maxHeapify(arr , n , largest);
    }
}


void buildHeap(int arr[] , int n){
    for(int i = (n-1)/2 ; i>=0 ; i--){
        maxHeapify(arr , n , i); // iske hisab se niche se ek root node garbad ha bas waise jab pura parent discover hoga tab tak sare apni jagah par honge and ek hi node pe chek hoga
    }
}



//Step 2 sort uisng the heap as front is always largest
void heapSOrt(int arr[] , int n){
    buildHeap(arr , n);
    for(int i = n-1 ; i>=1 ; i--){
        swap(arr[0] , arr[i]);
        maxHeapify(arr , i , 0);
    }
}

int main(){
    int arr[] = {1,8,12,98,144,67,243};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSOrt(arr , n);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<endl;
    }
    
    return 0;
}