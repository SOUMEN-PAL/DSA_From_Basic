#include<bits/stdc++.h>
using namespace std;
// bakwas question //

int C_Dis(int arr[] , int n , int m){
    sort(arr ,arr+n);
    int res = INT_MAX;
    for(int i = 0 ; i+m-1<n ; i++){
        res = min(res , arr[i+m-1]-arr[i]);
    }
    return res;
}



int main(){
    int arr[] = { 12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50 };
	int m = 7; // Number of students
	int n = sizeof(arr) / sizeof(arr[0]);
    cout<<C_Dis(arr , n , m)<<endl;
    
    return 0;
}