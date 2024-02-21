#include<bits/stdc++.h>
using namespace std;

int maxArea(int arr[] , int n){
    int res = 0;
    stack<int> s;
    for(int i = 0 ; i<n ; i++){
        while(s.empty() == false && arr[s.top()]>=arr[i]){
            int tp = s.top();
            s.pop();
            int curr = arr[tp]*(s.empty()?i : (i - s.top() - 1));
            res = max(res , curr);
        }
        s.push(i);
    }

    while(s.empty() == false){
        int tp = s.top();
        s.pop();
        int curr = arr[tp]*(s.empty() ? n : (n-s.top() - 1));
        res = max(curr , res);
    }
    return res;
}

int largestRectengle(vector<vector<int>> vec , int n , int m){
        int ans = INT_MIN;
        int arr[m] = {0};
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(vec[i][j] == 1){
                    arr[j] = arr[j] + vec[i][j];
                }
                else{
                    arr[j] = 0;
                }
            }
            int res = maxArea(arr , m);
            ans = max(res , ans);
        }
        return ans;
}

int main(){
    vector<vector<int>> vec = {{0,1,1,0} , {1,1,1,1} , {1,1,1,1} , {1,1,0,0}};
    int n = vec.size();
    int m = vec[0].size();

    int result = largestRectengle(vec , 4 , 4);
    cout<<result<<endl;

    return 0;
}