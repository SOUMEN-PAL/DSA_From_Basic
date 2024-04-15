#include <bits/stdc++.h>
using namespace std;

int check_bits(int pattern , int arr[] , int n){
    int count=0;
    for(int i = 0 ; i < n ; i++){
        if((pattern & arr[i]) == pattern){
            count++;
        }
    }
    return count;
}


int max_andvalue(int arr[] , int n){
    int res=0 , count;
    for(int bit = 31 ; bit>=0 ; bit-- ){
        count = check_bits((res|(1<<bit)) , arr , n );

        if(count>=2){
            res = res|(1<<bit);
        }

    }
    return res;
}


int main(){

    int arr[] = {4,8,16,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<max_andvalue(arr , n)<<endl;

    




    return 0;
}