#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l-1 , j = h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i>=j){return j;}
        swap(arr[i] , arr[j]);
    }
}


void Q_sort(int arr[], int low, int high) {
    if (low < high)
    {
        int p = partition(arr, low, high);
        cout<<p<<endl;
        Q_sort(arr, low, p-1);
        Q_sort(arr, p, high);
    }
}



int main() {
    int arr[] = {5,3,1,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    Q_sort(arr , 0 , n-1);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}