#include<bits/stdc++.h>
using namespace std;
// sorting function //
void merge(int arr[], int l, int m, int h){
    
    int n1=m-l+1, n2=h-m;
    int *left = new int[n1], *right = new int[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];    
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];    
}

void mergeSort(int arr[],int l,int r){
    if(r>l){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// naive solution //
int min_diff(int arr[] , int n){
    int res = INT_MAX;
    for(int i = 1 ; i<n ; i++){
        for(int j = 0 ; j<i ; j++){
            res = min(res , abs(arr[i] - arr[j]));
        }
    }
    return res;
}

// efficient solution //
int Min_difference(int arr[] , int n){
    mergeSort(arr , 0 , n-1);
    int res = INT_MAX;
    for(int i = 1 ; i<n ; i++){
        res = min(res , arr[i]-arr[i-1]);
    }
    return res;
}

int main(){
    int arr[] = {10,8,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<min_diff(arr , n)<<endl;
    cout<<Min_difference(arr , n)<<endl;
    return 0;
}