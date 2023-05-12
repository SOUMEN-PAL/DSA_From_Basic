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




int main(){
    int arr[] = {2,8,3,4,9,5};

    cout<<get_sum(arr,0,4)<<endl;



    return 0;
}