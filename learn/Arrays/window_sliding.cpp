#include<bits/stdc++.h>
using namespace std;

int sliding_window(int arr[] , int n , int k){
    int res = INT_MIN;
    for(int i = 0 ; i+k-1<n ; i++){
        int curr = 0;
        for(int j = 0 ; j<k ; j++){
            curr = curr + arr[i+j];
        }
        // for(int j = i ; j<i+k ; j++){
        //     curr = curr+arr[j];
        // } can also be done like this
        res = max(res , curr);
    }

    return res;


}



int main(){
    int arr[] = {18,30,-5,20,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k =3;

    cout<<sliding_window(arr , n , k)<<endl;


    return 0;
}