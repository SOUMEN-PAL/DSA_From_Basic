#include <bits/stdc++.h>
using namespace std;

void insertt(int arr[] , int n , int x , int cap , int pos){
    if(n==cap){
        cout<<"Cant inset in the array"<<endl;
    }
    else{// else me dalo warna move kar dega aur age ke valyues ko size ke bahar kar dega //
        int index = pos - 1;
        for(int i = n-1 ; i>=index ; i--){
            arr[i+1] = arr[i];
        }
        arr[index] = x;       
    }
}

int main(){
    int arr[4] = {1,34,21,5};
    int size = 4;
    int value = 24;
    int pos = 2;
    int capacity = 4;
    insertt(arr , size , value , capacity , pos);
    for(int i  = 0  ; i<4 ; i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}