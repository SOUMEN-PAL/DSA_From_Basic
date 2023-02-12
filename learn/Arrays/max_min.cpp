#include <bits/stdc++.h>
using namespace std;

void max_min(int arr[] , int n , int &max , int &min){

    for(int i = 1 ; i<n ; i++){
        if(arr[i]>arr[max]){
            max = i;
        }

        if(arr[i]<arr[min]){
            min = i;
        }
    }



}


int main(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_in = 0;
    int min_in = 0;
    max_min(arr , n , max_in , min_in);
    cout<<arr[max_in]<<" "<<arr[min_in]<<endl;
    



    return 0;
}