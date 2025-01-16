#include<bits/stdc++.h>
using namespace std;

bool isValid(int time, int k, vector<int>& arr) {
    int workers = 1; 
    int n = arr.size();

    int lastPosition = arr[0]; 

    for (int i = 1; i < n; i++) {
        if (arr[i] > lastPosition + 2 * time) {
            workers++;
            lastPosition = arr[i];
        }
        if (workers > k) return false; 
    }

    return workers <= k;
}

int MaxOfMinWaiting(int n , vector<int> arr){
    sort(arr.begin() , arr.end());
    int high = arr[n-1];
    int low = 0;
    int res = -1;
    while(low<=high){
        int time = low + (high - low)/2;
        
        if(isValid(time , 3 , arr)){
            res = time;
            high = time - 1;
        }
        else{
            low = time + 1;
        }
        
    }
    return res;
}


int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);

        for(int i = 0 ; i<n ; i++){
            cin>>arr[i];
        }

        cout<<MaxOfMinWaiting(n , arr)<<endl;

    }
    
    
    return 0;
}