#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void insertion_Sort(int arr[] , int n){
    for(int i = 1 ; i<n ; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// naive Solution //

// int * mergeTwoSorted(int A[] , int n , int B[] , int m){
//     int res[m+n];
//     for(int i = 0 ; i<n ; i++){
//         res[i] = A[i];
//     }
//     for(int i = 0 ; i<m ; i++){
//         res[i+n] = B[i];
//     }

//     insertion_Sort(res , m+n);

//     for(int i = 0 ; i<m+n ; i++){
//         cout<<res[i]<<" ";
//     }

//     return res;

// }


vector<int> Merge_Two_sorted(int arr[] , int n , int brr[] , int m){
    int i = 0 , j = 0;
    vector<int> ans;
    while(i<n && j<m){
        if(arr[i]<=brr[j]){
            ans.push_back(arr[i]);
            
            i++;
        }
        else if(brr[j]<arr[i]){
            ans.push_back(brr[j]);
            
            j++;
        }
    }
    while(i<n){
        ans.push_back(arr[i]);
        i++;
    }
    while(j<m){
        ans.push_back(brr[j]);
        j++;
    }
    
    return ans;
}





int main(){
    int A[] = {2,3,4,5,9};
    int B[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(A[0]),m = sizeof(B)/sizeof(B[0]);

    // int *p = mergeTwoSorted(A , n , B , m);
    // cout<<endl;
    vector<int> res = Merge_Two_sorted(A , n , B , m);
    for(int i = 0 ; i < res.size() ; i++){
        cout<<res[i]<<" ";
    }
    
    return 0;
}