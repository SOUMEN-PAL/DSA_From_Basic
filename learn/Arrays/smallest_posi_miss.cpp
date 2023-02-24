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
int missingNumber(int arr[] , int n){
    sort(arr,arr+n);
    int ind = indexi(arr , n);
    int i =1;
    while(i<n){
        if(arr[ind]!=i){
            return i;
        }
        
        return i+1;
        
        i++;
        ind++;
    }
}

int main(){
    
    int arr[] = {1 ,2 ,3 ,4 ,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<missingNumber(arr,n);

    return 0;
}