#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[] , int x , int low , int high){
    
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid]<x){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}


int Unbounded_binary_search(int arr[] , int x){
    int i = 1;
    while(arr[i]<x){
        i = i*2;
    }
    if(arr[i] == x){
        return i;
    }
    return binary_search(arr , x , (i/2) + 1 , i-1);
}



int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,12,13,14,15,16,20 , 100 , 101 , 200 , 300 , 350 , 400 , 700 , 900 , 3443, 666666};
    int x;
    cout<<"Enter the element to be searched: ";
    cin>>x;

    cout<<"The element is present at index: "<<Unbounded_binary_search(arr , x)<<endl;
    
    return 0;
}
