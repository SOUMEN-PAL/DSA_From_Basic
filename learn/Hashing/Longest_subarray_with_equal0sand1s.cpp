#include<bits/stdc++.h>
using namespace std;


// naive solution //
int longest_1sand0s(int arr[] , int n){
    int res = 0 , count1 = 0 , count0 = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = i ; j<n ; j++){
            if(arr[j] == 0){
                count0++;
            }
            else{
                count1++;
            }
            if(count1 == count0){
                res = max(res , j-i + 1);
            }
        }
        count0 = 0;
        count1 = 0;
    }
    return res;
}


int main(){
    int arr[] = {1,0,1,1,1,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longest_1sand0s(arr , n)<<endl;

    return 0;
}