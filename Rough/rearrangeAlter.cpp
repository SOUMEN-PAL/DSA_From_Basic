#include<bits/stdc++.h>
using namespace std;

void alter(int arr[] , int n){
    sort(arr, arr+n);
    int maxi = arr[n-1]+1;
    int max = n-1;
    int min = 0;

    for(int i = 0 ; i<n ; i++){
        if(i%2==0){
            arr[i] = arr[i] + ((arr[max]%maxi) * maxi);
            max--;
        }
        else{
            arr[i] = arr[i] + ((arr[min]%maxi)*maxi);
            min++;
        }
    }

    for(int i = 0 ; i< n ; i++){
        arr[i] = arr[i]/maxi;
    }
}


int main(){
    int arr[] = {1,4,5,6,7,8,3,67,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    alter(arr,n);
    cout<<"{ ";
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"}";

    return 0;
}