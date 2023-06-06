#include<bits/stdc++.h>
using namespace std;

// niave solution //

int last_occurence(int arr[] , int n , int x)
{
    for(int i = n ; i>=0 ; i--){
        if(arr[i]==x){
            return i;
            break;
        }
    }
    return -1;
}





//_________________efficient solution____________________//
int lasr_occurence(int arr[] , int low , int high , int x , int n){
    while(high>=low){
        int mid = (low+high)/2;
        if((x<arr[mid+1] || mid == n-1) && arr[mid] == x ){
            return mid;
        }
        else if(x<arr[mid]){
            high = mid-1 ;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}



int main(){

    int arr[] = {1,2,2,2,2,3,3,3,3,4,4,4,4,6,6,6,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"Enter the number: ";
    cin>>x;
    cout<<"Last index of the number "<<x<<" is: "<<lasr_occurence(arr , 0 , n-1 , x , n)<<endl;
    cout<<"Last index of the number "<<x<<" is: "<<last_occurence(arr , n , x)<<endl;



    return 0;
}