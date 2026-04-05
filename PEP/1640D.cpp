#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

bool isValid(int time, int k, vector<int>& arr) {
    int workers = 1; 
    int n = arr.size();

    int range = arr[0]; 

    for (int i = 1; i < n; i++) {
        if (arr[i] > range + 2 * time) {
            workers++;
            range = arr[i];
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