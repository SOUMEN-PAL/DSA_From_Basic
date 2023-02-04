#include <bits/stdc++.h>
using namespace std;

int sea(int arr[] , int n , int element){
    for(int i = 0 ; i<n ; i++){
        if(element==arr[i]){
            return i;
        }


    }
    return -1;
}

int main(){
    int arr[] = {1,2,4,5,6,7,8,90,12};
    int n  =  sizeof(arr)/sizeof(arr[0]);
    int searchi = 90;
    cout<<sea(arr , n , searchi)<<endl;


    return 0;
}