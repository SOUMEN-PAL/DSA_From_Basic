#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int l, int m, int h){
    
    int n1=m-l+1, n2=h-m;
    int left[n1],right[n2];
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

int main() {
	
    int a[]={10,5,30,15,76,41,16,4,1,64,6,46,42,6,46,6,6,6,6,11,5,1,5,11,1,5,15,1,51,5,2,121,54,51,2,16,43,6,4,3,1};
	int l=0,r=sizeof(a)/sizeof(a[0]);
	
	mergeSort(a,l,r);
	for(int x: a)
	    cout<<x<<" ";
}