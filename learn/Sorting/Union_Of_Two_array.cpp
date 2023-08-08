#include<bits/stdc++.h>
using namespace std;

//_________________________naive solution________________//
void Union_Array(int arr[] , int brr[] , int n , int m){
    vector<int> res;
    for(int i = 0 ; i<n ; i++){
        res.push_back(arr[i]);
    }
    for(int i = 0 ; i<m ; i++){
        res.push_back(brr[i]);
    }
    sort(res.begin() , res.end());
    for(int i = 0 ; i<m+n ; i++){
        if(i==0 || res[i]!=res[i-1]){
            cout<<res[i]<<" ";
        }
    }
    cout<<endl;
}

//__________Efficient SOlution_____________//
void Union_Sorted_Array(int arr[] , int brr[] , int n , int m){
    int i = 0 , j = 0;
    while(i<n && j<m){
        if(i>0 && arr[i-1]==arr[i]){
            i++;
            continue;
        }
        if(j>0 && brr[j-1] == brr[j]){
            j++;
            continue;
        }
        if(arr[i]<brr[j]){
            cout<<arr[i++]<<" ";
            
        }
        else if(arr[i]>brr[j]){
            cout<<brr[j++]<<" ";
            
        }
        else{
            cout<<arr[i]<<" ";
            i++;
            j++;
        }
    }
    while(i<n){
        if(i>=0 && arr[i-1] != arr[i]){
            
            cout<<arr[i++]<<" ";
        }
    }
            
    while(j<m){
        if(j>=0 && arr[j-1] != arr[j]){
            
            cout<<brr[j++]<<" ";
        }
    }
}



int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int brr[] = {1,1,3,4,6,6,7,8,9,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = sizeof(brr)/sizeof(brr[0]);
    Union_Array(arr , brr , n , m);
    Union_Sorted_Array(arr , brr , n, m);
    
    return 0;
}