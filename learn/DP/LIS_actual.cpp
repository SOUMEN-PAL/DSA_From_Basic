#include<bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

//n log n solution
int upperBound(vector<int> tail , int target){
    int low = 0 , high = tail.size();

    while(low < high){
        int mid = low + (high - low)/2;

        if(tail[mid] < target){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    return low;
}
int lengthOfLIS(vector<int>& arr) {
    vector<int> tail;
    int n = arr.size();
    for(int i = 0 ; i<n ; i++){
        if (tail.empty() || arr[i] > tail.back()) {
            tail.push_back(arr[i]);
        } else {
            int index = upperBound(tail, arr[i]);
            tail[index] = arr[i];
        }
    }
    return tail.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }
    
    int ans = sol(arr , n);
    cout<<ans<<endl;
    
    return 0;
}