#include<bits/stdc++.h>
using namespace std;

void move(int arr[] , int n){
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        if(arr[i]!=0){
            swap(arr[i] , arr[count]);
            count++;
        }
    }


    cout<<"The new array is: ";
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



int main(){

    int arr[] = {1,0,3,0,0,0,8,6,0,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    move(arr , n);
    
    return 0;
}