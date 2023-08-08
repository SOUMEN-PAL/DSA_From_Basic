#include<bits/stdc++.h>
using namespace std;


//_________________________naive solution________________________ //
vector<int> intersectionOfTwoSortedArray(int arr[] , int brr[] , int n , int m){
    vector<int> res;
    for(int i = 0 ; i<n ; i++){
        if(i>0 && arr[i+1] == arr[i]){
            continue;
        }
        for(int j = 0 ; j<m ; j++){
            if(arr[i]==brr[j]){
                res.push_back(arr[i]);
                break;
                
            }
        }
    }
    return res;
}

//______________________________Efficient Solution_________________________//
void Intersection_sorted(int arr[] , int brr[] , int n , int m){
    int i = 0 , j = 0;
    while(i<n && j<m){
        if(i>0 && arr[i-1] == arr[i]){
            i++;
            continue;
        }
        if(arr[i]<brr[j]){
            i++;
        }
        if(arr[i]>brr[j]){
            j++;
        }
        if(arr[i] == brr[j]){
            cout<<arr[i]<<" ";
            i++;
            j++;
        }
    }
}



int main(){
    int arr[] = {1,2,2,2,3,4,5,5,6,7,8,9};
    int brr[] = {1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4,5,6,7 , 9};
    int n = sizeof(arr)/sizeof(arr[0]) , m = sizeof(brr)/sizeof(brr[0]);
    vector<int> ans = intersectionOfTwoSortedArray(arr , brr , n , m);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    Intersection_sorted(arr , brr , n , m);
    return 0;
}