#include<bits/stdc++.h>
using namespace std;

// Brute FOrce Solution //
vector<int> max_minOfEverySubArray(vector<int> arr){
    int n = arr.size();
    vector<int>ans(n , 0);
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n-i ; j++){
            int num = INT_MAX;
            for(int k = j ; k<i+1+j;k++){
                num = min(num , arr[k]);
            }
            ans[i] = max(ans[i] , num);
        }
    }
    return ans;
}

// Slightly Better Solution //

// Preprocessing //
vector<int> PSE(vector<int> arr){
    int n  = arr.size();
    stack<int> s;
    vector<int> res;
    for(int i = 0 ; i<n ; i++){
        while(s.empty() == false && arr[i]<=arr[s.top()]){
            s.pop();
        }
        int p = s.empty()?-1:s.top();
        res.push_back(p);
        s.push(i);
    }
    return res;
}
// Preprocessing //
vector<int> NSE(vector<int> arr){
    int n = arr.size();
    stack<int> s;
    vector<int> res;
    for(int i = n-1 ; i >= 0 ; i--){
        while(s.empty() == false && arr[i]<=arr[s.top()]){
            s.pop();
        }
        int p = s.empty()?n:s.top();
        res.push_back(p);
        s.push(i);
    }
    reverse(res.begin() , res.end());
    return res;
}


vector<int> max_min_sub(vector<int> arr){
    int n = arr.size();
    vector<int> previous_smaller = PSE(arr);
    vector<int> next_smaller = NSE(arr);
    vector<int> res(n , 0);
    for(int i = 0 ; i<n ; i++){
        int places = next_smaller[i]-previous_smaller[i] - 1;
        for(int j = 0 ; j<places ; j++){
            res[j] = max(res[j] , arr[i]); // arr[i] woh element ha jisse pucha jaa raha ha //
        }
    }
    return res;
}


// Most Efficient Solution //
vector<int> maxOfMinOfEverySizeSubarray(vector<int> arr){
    int n = arr.size();
    vector<int> res(n , 0);
    stack<int> s;
    for(int i = 0 ; i<n ; i++){
        while(s.empty() == false && arr[i]<=arr[s.top()]){
            int index = s.top();
            s.pop();
            int places = s.empty()?i:i-s.top()-1;
            res[places-1] = max(res[places-1] , arr[index]);
        }
        s.push(i);
    }
    while(s.empty() == false){
        int index = s.top();
        s.pop();
        int places = s.empty()?n:n-s.top()-1;
        res[places-1] = max(res[places-1] , arr[index]);
    }

    for(int i = n-2 ; i>=0 ; i--){
        res[i] = max(res[i] , res[i+1]);
    }
    return res;
}

int main(){
    vector<int> arr = {10,20,30,50,10,70,30};
    vector<int> ans = maxOfMinOfEverySizeSubarray(arr);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}
