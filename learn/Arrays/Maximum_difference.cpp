#include <bits/stdc++.h>
using namespace std;

// naive solution //

void diff(int arr[] , int n){
    int temp;
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            temp = max(temp , (arr[j]-arr[i]));
        }
    }

    cout<<temp<<endl;
}

// efficient solution //




int main(){
    int arr[] = {30,10,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    diff(arr , n);
    


    return 0;
}