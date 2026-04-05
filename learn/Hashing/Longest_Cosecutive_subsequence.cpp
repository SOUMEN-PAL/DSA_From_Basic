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

// Naive Solution //
int longest(int arr[] , int n){
    sort(arr , arr+n); // Method 1 by sorting //
    int curr = 1;
    int res = 1;
    for(int i = 1 ; i<n ; i++){
        if(arr[i] == arr[i-1] + 1){
            curr++;
            res = max(res , curr);
        }
        else if(arr[i] != arr[i-1]){ // dealing and ignoring the repeated element buy not doing anythong for arr[i] == arr[i-1]//
            res = max(res , curr);
            curr = 1;
        }
    }
    return res;
}

// Efficient Solution //
int Longest_Consecutive_sequrnce(int arr[] , int n){
    unordered_set<int> s(arr , arr+n);
    int res = 0;
    for(auto i : s){
        if(s.find(i-1) == s.end()){
            int curr =1;
            while(s.find(i+curr) != s.end()){
                curr++;
            }
            res = max(curr , res);
        }
    }
    return res;
}

int main(){
    int arr[] = {1,9,3,4,2,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longest(arr , n)<<endl;
    cout<<Longest_Consecutive_sequrnce(arr , n)<<endl;
    return 0;
}