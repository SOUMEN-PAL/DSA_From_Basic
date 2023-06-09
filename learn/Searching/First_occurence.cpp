#include<bits/stdc++.h>
using namespace std;


// naive solution //
int first_occ(int arr[] , int n , int x){
    for(int i = 0 ; i<n ; i++){
        if(arr[i]==x){
            return i;
            break;
        }
        
    }
    return -1;
}





// ________________efficient solution____________________  Unknown approach//

int first_occurence(int arr[] , int low , int high , int x , int n){
    if(high>=low){
        int mid = low+(high-low)/2;
        if((mid==0 || arr[mid-1]<x) && arr[mid]==x){
            return mid;
        }
        else if(x>arr[mid]){
            return first_occurence(arr , mid+1 , high , x , n);
        }
        else{
            return first_occurence(arr , low , mid-1 , x , n);
        }
    }
    else{
        return -1;
    }
}

// GFG approach //
int firstOccurence(int arr[] , int n , int x){
    int high = n-1 , low = 0;
    
    while(high>=low){
        int mid = (low+high)/2;    
        if(x>arr[mid]){
            low = mid+1;
        }
        else if(x<arr[mid]){
            high = mid-1;
        }
        else{// only left is arr[mid]==x //
            if(mid == 0 || arr[mid-1] != arr[mid]){
                return mid;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}


int main(){
    int arr[] = {1,1,2,2,2,2,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"Enter the key: ";
    cin>>x;

    cout<<"The starting index is: "<<first_occurence(arr , 0 , n-1 , x , n)<<endl;
    cout<<"The starting index is: "<<first_occ(arr , n , x)<<endl;
    cout<<"The starting index is: "<<firstOccurence(arr , n , x)<<endl;
    return 0;
}