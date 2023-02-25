#include <bits/stdc++.h>
using namespace std;

int incre(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        if(arr[i]>0){
            return i;
            break;
        }
    }
}




int main(){
    
    int arr[] = {0,1 ,2 ,3 ,4 ,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<incre(arr , n);

    return 0;
}