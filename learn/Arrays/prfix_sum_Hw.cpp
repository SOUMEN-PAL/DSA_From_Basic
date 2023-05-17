#include<bits/stdc++.h>
using namespace std;

vector<int> presum(int arr[] , int n){
    int sum = 0;
    vector <int> res(n);
    for(int i = 0 ; i<n ; i++){
        sum = sum+arr[i];
        res[i] = sum;
    }

    return res;
}

int wsum(int arr[] , int l , int r){

    int sum = 0;
    for(int i = l ; i<=r ; i++){
        sum = sum + i*arr[i];        
    }
    return sum;
}

int getWsum(int arr[] , int n , int l  , int r){
    vector<int> ans = presum(arr , n);
    int We_sum = wsum(arr , l , r);
    if(l==0){
        return We_sum - (l-1)*(ans[r]);
    }
    return We_sum - (l-1)*(ans[r] - ans[l-1]);

}



int main(){

    int arr[] = {2,3,5,4,6,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int l = 2 , r = 3;
    cout<<getWsum(arr , n , l , r);

    return 0;
}