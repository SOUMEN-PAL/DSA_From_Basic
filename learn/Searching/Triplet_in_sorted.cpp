#include<bits/stdc++.h>
using namespace std;

// Naive solution //
bool isTriplet(int arr[] , int n , int x){
    for(int i = 0 ; i<n-2 ; i++){
        for(int j = i+1 ; j<n-1  ; j++){
            for(int k = j+1 ; k<n ; k++){
                if(arr[i] + arr[j] + arr[k] == x){
                    return true;
                }
            }
        }
    }
    return false;
}

// Efficient Solution //
bool isPair(int arr[] , int l , int n , int x){
    
    int h = n-1;
    while(h>l){
        int sum = arr[l] + arr[h];
        if(sum==x){
            return true;
        }
        else if(sum>x){
            h--;
        }
        else{
            l++;
        }
    }
    return false;
}


bool ifTriplet(int arr[] , int n , int x){
    sort(arr , arr+n);
    for(int i = 0 ; i<n ; i++){
        if(isPair(arr , i+1 , n , (x-arr[i]))){
            return true;
        }
    }
    return false;

}


int main(){
    int arr[] = {2,3,5,6,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 20;
    if(isTriplet(arr , n , x)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    if(ifTriplet(arr , n , x)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }



    return 0;
}