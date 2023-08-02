#include <bits/stdc++.h>
using namespace std;

void mergeSort(int arr[] , int low , int mid , int high){
    int n1 = mid - low + 1 , n2 = high - mid;
    int Array1[n1];
    int Array2[n2];
    for(int i = 0 ; i<n1 ; i++){
        Array1[i] = arr[low + i];
    }
    for(int i = 0 ; i<n2 ; i++){
        Array2[i] = arr[mid+1+i];
    }
    int i = 0 , j = 0 , k = low;
    while(i<n1 && j<n2){
        if(Array1[i]<=Array2[j]){
            arr[k] = Array1[i];
            k++;
            i++;
        }
        else{
            arr[k] = Array2[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = Array1[i];
        k++;
    }
    while(j<n2){
        arr[k] = Array2[j];
        j++;
        k++;
    }
}



int main(){
    int arr[] = {1,2,3,4,5,6,1,10,30,40};
    int low = 0 , mid = 5 , high = 9;
    mergeSort(arr , low , mid , high);
    for(int i:arr){
        cout<<i<<" ";
    }


    return 0;
}
