#include<bits/stdc++.h>
using namespace std;

// Naive Solution //
void dis(int arr[] , int n , int k){
    for(int i = 0 ; i<=n-k ; i++){
        int count = 0;
        for(int j = 0 ; j<k ; j++){
            bool flag = false;
            for(int p = 0 ; p<j ; p++){
                if(arr[i+j] == arr[i+p]){
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                count++;
            }
        }
        cout<<count<<" ";
    }
    cout<<endl;
}

// Efficient solution //
// TC : O(n) AS : O(n) for the map
void DistinceInTheWindow(int arr[] , int n , int k){
    unordered_map<int , int> mp;
    for(int i = 0 ; i<k ; i++){
        mp[arr[i]]++;
    }
    cout<<mp.size()<<" ";
    for(int i = k ; i<n ; i++){
        mp[arr[i-k]] -=1;
        if(mp[arr[i-k]] == 0){
            mp.erase(arr[i-k]);
        }
        mp[arr[i]] +=1;
        cout<<mp.size()<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[] = {10, 20 , 20 , 10 , 30 , 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    dis(arr , n , 4);
    DistinceInTheWindow(arr , n , 4);
    return 0;
}