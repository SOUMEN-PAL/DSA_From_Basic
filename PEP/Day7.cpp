#include<bits/stdc++.h>
using namespace std;


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



int lume(int arr[],  int low , int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j = low ; j<=high-1 ; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[i+1] , arr[high]);
    return i+1;
}


int quickSelect(int arr[], int s, int e, int n) {
    if (s <= e) {
        // Generate a random pivot index
        int p = rand() % (e - s + 1) + s;
        // Partition the array around the pivot
        int k = lume(arr, s, e);
        
        // Check if the pivot's final position is the n-1 element we're looking for
        if (k == n - 1)
            return arr[k];
        else if (k > n - 1)
            return quickSelect(arr, s, k - 1, n);
        else
            return quickSelect(arr, k + 1, e, n);
    }
    return -1;
}


int main() {
	
    int arr[]={2,4,1,3,5};
	int l=0,r=sizeof(arr)/sizeof(arr[0]);
	
	cout<<quickSelect(arr , l , r-1 , 4);

}