#include <bits/stdc++.h>
using namespace std;

int largest(int arr[] , int n){
    int temp=0;
    for(int i = 0 ; i<n  ;i++){
        if(arr[i]>temp){
            temp = arr[i]; // naive approach //
        }
        else{
            temp = temp;
        }
    }
    return temp;
}


int main(){
    int arr[] = {1,2,3,478,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<largest(arr , n)<<endl;



    return 0;
}