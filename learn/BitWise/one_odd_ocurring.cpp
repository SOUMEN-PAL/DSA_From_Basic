#include <iostream>
using namespace std;
// naive solution //
int odd_one(int arr[], int n){
    for(int i=0 ; i<n; i++){
        int count=0;
        for(int j = 0 ; j<n ; j++){
            if (arr[i]==arr[j]){
                count++;

            }

        }
        if(count%2!=0){
            return arr[i];
        }

    }
}
// Efficient solution //
int oddone(int arr[] , int n){
    int res=0;
    for(int i=0 ; i<n ; i++){
        res=res^arr[i];
    }
    if(res){
        return res;
    }
    else{
        return -1;
    }
}

int main(){
    int arr[]={1,1,1,1,2,2,2,2,4,4,4,4,10,10,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<odd_one(arr,n)<<endl;
    cout<<oddone(arr,n)<<endl;
    
    return 0;
}