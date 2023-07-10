#include<bits/stdc++.h>
using namespace std;


int Traping_waterII(int arr[] , int n){
    int l = 0 , h = n-1;
    int res = INT_MIN;
    while(h>l){
        res = max(res , (h-l-1)*min(arr[h] , arr[l]));
        if(arr[h]>arr[l]){
            l++;
        }
        else{
            h--;
        }
    }
    return res;
}



int main(){
    
    return 0;
}