#include<bits/stdc++.h>
using namespace std;

// Naive Solution //
bool ifPair(int arr[] , int n , int x){
    for(int i = 0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(arr[i] + arr[j] == x){
                return true;
            }
        }
    }
    return false;
}


//____________________Two Pointer Approach_____________________//
// Efficient Solution //

bool isPair(int arr[] , int n , int x){
    int l = 0 , h = n-1;
    while(l<h){
        int sum = arr[l] + arr[h];
        if( sum == x){
            return true;
        }
        else if(sum>x){
            h = h - 1;
        }
        else{
            l = l + 1;
        }
    }
    return false;
}




int main(){
    int arr[] = {10 , 34 , 45, 67 , 99};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int x = 44;

    if(ifPair(arr , n , x)){
        cout<<"Sum Exist...."<<endl;
    }
    else{
        cout<<"No such pair exists......"<<endl;
    }


    if(isPair(arr , n , x)){
        cout<<"Sum Exist...."<<endl;
    }
    else{
        cout<<"No such pair exists......"<<endl;
    }
    return 0;
}