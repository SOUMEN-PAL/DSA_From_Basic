#include <bits/stdc++.h>
using namespace std;

void detlete_Array(int arr[] , int &n , int ele){
    int ind = 0;
    for(int i = 0 ; i<n ; i++){
        if(arr[i]==ele){
            ind=i;
            break;
        }


    }
    if(ind == 0){
        cout<<"Element not present in the array"<<endl;
    }
    else{
        for(int i = ind ; i<n ; i++){
            arr[i]=arr[i+1];
        }
        n=n-1;
    }


}

int main(){
    int arr[] = {1,2,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int element = 43;
    detlete_Array(arr , n , element);
    for(int i = 0; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}