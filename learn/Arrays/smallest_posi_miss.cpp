#include <bits/stdc++.h>
using namespace std;

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

int main(){
    
    int arr[] = {1 ,2 ,3 ,4 ,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<missingNumber(arr,n);

    return 0;
}