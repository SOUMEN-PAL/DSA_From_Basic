#include<bits/stdc++.h>
using namespace std;

// naive_soluton //
bool subarray_with_given_sum(int arr[] , int n  , int sum){
    for(int i = 0 ; i<n ; i++){
        int curr = 0;
        for(int j = i ; j<n  ; j++){
            curr+=arr[j];
            if(curr==sum){
                return true;
            }
        }
    }
    return false;
}


// Efficiet solution //
bool sub_arr_given_sum(int arr[] , int n , int sum){
    int s = 0 , curr = 0;
    for(int i = 0 ; i<n ; i++){
        curr+=arr[i];
        while(curr>sum && s<i){
            curr-=arr[s];
            s++;
        }
        if(curr==sum){
            cout<<i<<" "<<s<<endl;
            return true;
        }
    }
    return false;

}

int subb_arr_given_sum(int arr[], int n, int sum) {
    int s = 0;
    int curr = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        curr += arr[i];
        while (curr > sum && s < i) {
            curr -= arr[s];
            s++;
        }
        if (curr == sum) {
            count++;
        }
    }

    return count;
}


int main(){
    int arr[] = {10,2,-2,-20,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = -10;

    bool ans = sub_arr_given_sum(arr , n , sum);
    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    cout<<subb_arr_given_sum(arr , n , sum);
 
    

    

    
    return 0;
}