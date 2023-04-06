#include<bits/stdc++.h>
using namespace std;


int checkbit(int pattern , int arr[] , int n){
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        if((pattern & arr[i]) == pattern){ // brackets are needed here //
            count++;
        }
    }

    return count;
}


int max_and(int arr[] , int n){
    int res = 0 , count;

    for(int i = 31 ; i>=0 ; i--){
        count = checkbit((res|(1<<i)), arr , n);
    

        if(count>=2){
            res = res|(1<<i);
        }
    }
    return res;
}


int main(){
    int arr[] = {4,8,16,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<max_and(arr , n)<<endl;

    return 0;
}