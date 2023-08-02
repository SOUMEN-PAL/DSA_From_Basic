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





//_________________efficient solution_____________________//
int lasr_occurence(int arr[] , int x , int n){
    int high = n-1;
    int low = 0;
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

// GFG Approach //
int lastOccurence(int arr[] , int n  , int x){
    int high = n-1 , low = 0;
    while(high>=low){
        int mid = (low+high)/2;
        if(x>arr[mid]){
            low = mid+1;
        }
        else if(x<arr[mid]){
            high = mid - 1;
        }
        else{
            if(mid == n-1 || arr[mid+1] != arr[mid]){
                return mid;
            }
            else{
                low = mid+1;
            }
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
    cout<<"Last index of the number "<<x<<" is: "<<lasr_occurence(arr , x , n)<<endl;
    cout<<"Last index of the number "<<x<<" is: "<<last_occurence(arr , n , x)<<endl;
    cout<<"Last index of the number "<<x<<" is: "<<lastOccurence(arr , n , x)<<endl;


    return 0;
}