#include <bits/stdc++.h>
#include <math.h>
using namespace std;

/*
int indexi(int arr [], int n){
    for(int i = 0 ; i<n ; i++){
        if(arr[i]>0){
            return i;
            break;
        }
    }
}
    
    //Function to find the smallest positive number missing from the array.
int missingNumber(int arr[], int n) 
{ 
        // Your code here
    sort(arr , arr+n);
    int in = indexi(arr , n);
    int i = 1;
    while(in<=n){
        if(arr[in]!=i){
            return i;
        }
        i++;
        in++;
    }
} 
------------My approach------------
*/

// GFG approach //

int missing(int arr[] , int n){
    for(int i = 0 ; i<n ;i++){
        if(arr[i]<=0){
            arr[i] = n+2;
        }
    }
    for(int i = 0 ; i<n ; i++){
        int x =  abs(arr[i]);
        if(x<=n && arr[x-1]>0){
            arr[x-1] = - arr[x-1];
        }

    }
    for(int i = 0 ; i<n ; i++){
        if(arr[i]>0){
            return i+1;
        }
    }
    return n+1;
}

/*
wrong answer comming

int mis(int arr[] , int n){
    sort(arr,arr+ n);

    int x = 1;
    for(int i = 0  ; i<n ; i++){
        if(arr[i]<0){
            continue;
        }
        else{
            if(arr[i]>0){
                if(arr[i]==x){
                    x++;
                }
            }
        }
    }
    return x;
}
*/



int main(){
    
    int arr[] = {1 ,5 ,3 ,4 ,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<missing(arr , n)<<endl;




    return 0;
}