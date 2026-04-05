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

// Observation of the problem 
// Checking for the brute force approach
// what is the problem in the brute force what is increasing the time complexity
// Remove that problem


// Naive approach //
vector<pair<int , int>> twoSum(vector<int> arr , int n , int sum){
    vector<pair<int , int>> res;
    for(int i = 0 ; i<n-1 ; i++){
        
        for(int j = i+1 ; j<n ; j++){
            if(arr[i] + arr[j] == sum){
                pair<int , int> p = make_pair(i , j);
                res.push_back(p);        
            }
        }
    }
    return res;
}


// Efficient solution //
vector<vector<int>> isPair(vector<int> arr , int n , int target){
    unordered_set<int> hs;
    vector<vector<int>> res;
    hs.insert(arr[0]);
    for(int i = 1 ; i<n ; i++){
        int b = target - arr[i];
        if(hs.find(b) != hs.end()){
            vector<int> temp = {arr[i] , b};
            res.push_back(temp);
        }
        hs.insert(arr[i]);
    }
    return res;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int n = arr.size();

    vector<vector<int>> res = isPair(arr , n , 10);

    for(auto i : res){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    


    return 0;
}