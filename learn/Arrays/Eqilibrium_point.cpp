#include <iostream>
using namespace std;


// namive solution //
bool equi_point(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        int ls = 0 , rs = 0;
        for(int j = 0 ; j<i ; j++){
            ls +=arr[j];
        }
        for(int k = i+1 ; k<n ; k++){
            rs +=arr[k];
        }
        if(ls==rs){
            return true;
        }

    }
    return false;
}

// little efficient solution //

bool Equi_point(int arr[] , int n){
    int ls[n];
    int rs[n];
    int sum =0;
    for(int i = 0 ; i<n ; i++){
        sum +=arr[i];
        ls[i] = sum;
    }
    int sum2 = 0;
    for(int i = n-1 ; i>=0 ; i--){
        sum2 +=arr[i];
        rs[i] = sum2;
    }
    cout<<"Prefix sum: ";
    for(int i = 0 ; i< n  ; i++){
        cout<<ls[i]<<" ";
    }
    cout<<endl;

    cout<<"Suffix sum: ";
    for(int i = 0 ; i< n  ; i++){
        cout<<rs[i]<<" ";
    }
    cout<<endl;

    if(ls[n-2]==0 || rs[1]==0){
        return true;
    }
    for(int i = 1 ; i<n-1 ; i++){
        if(ls[i-1]==rs[i+1]){
            return true;
        }

    }
    return false;



}

// Efficient Solution //

bool Equii_point(int arr[] , int n){
    int rs = 0 ; 
    for(int i = 0 ; i<n ; i++){
        rs+=arr[i];
    }
    int ls = 0;
    for(int i = 0 ; i<n ; i++){
        rs = rs = arr[i];
        if(ls==rs){
            return true;
        }
        ls = ls+arr[i];
    }

    return false;
}



int main(){

    int arr[] = {9,2,3,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(equi_point(arr , n)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    if(Equi_point(arr , n)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    if(Equii_point(arr , n)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }






    return 0;
}