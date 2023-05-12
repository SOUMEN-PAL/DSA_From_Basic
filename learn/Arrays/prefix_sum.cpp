#include<bits/stdc++.h>
using namespace std;

// naive solution //
int get_sum(int arr[] , int a , int b){
    int sum = 0;
    for(int i = a ; i<=b ; i++){
        sum+=arr[i];
    }
    return sum;
}


// efficient solution //

int get_Sum(int arr[] , int n, int l  , int r){

    int pre[n];
    int sum = 0;

    for(int i = 0 ; i<n ; i++){
        sum += arr[i];
        pre[i] = sum;
    }
    if(l==0){
        return pre[r];
    }
    else{
        return pre[r]-pre[l-1];// l-1 because i wat the current at the left index and to get it i must 
    }

}




int main(){
    int arr[] = {2,8,3,4,9,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<get_Sum(arr ,n,1,4)<<endl;



    return 0;
}