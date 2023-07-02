#include<bits/stdc++.h>
using namespace std;

int Repeated_element(int arr[] , int n){
    int slow = arr[0]+1 , fast = arr[0]+1;
    do{
        slow = arr[slow]+1;
        fast = arr[arr[fast]+1]+1;
    }while(slow != fast);

    slow = arr[0]+1;
    while(slow != fast){
        slow = arr[slow]+1;
        fast = arr[fast]+1;
    }

    return slow-1;
}




int main(){
    int arr[] = {0 , 1 , 2 , 4, 3 , 5 , 6 , 7  , 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Repeated_element(arr , n)<<endl;
    
    return 0;
}