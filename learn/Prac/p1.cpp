#include <bits/stdc++.h>
using namespace std;

void rem_dup(int arr[] , int n){
    int temp[n];
    temp[0] = arr[0];
    int res = 1;

    for(int i = 0 ; i<n ; i++){
        if(temp[res-1]!=arr[i]){
            temp[res] = arr[i];
            res++;
        }
    }


}


void dupp(int arr[] , int n){
    int res = 1;
    for(int i = 1 ; i<n  ; i++){
        if(arr[i]!= arr[i-1]){
            arr[res] = arr[i];
            res++;

        }
    }
}


int main(){
    

	cout<<"hello world"<<endl;

    return 0;
}
