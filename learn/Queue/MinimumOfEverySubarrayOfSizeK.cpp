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

void minOfEverySubarraySizeK(int arr[] , int n , int k){
    deque<int> dq;
    for(int i = 0 ; i<k ; i++){
        while(!dq.empty() && arr[i]<=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i = k ; i<n ; i++){
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[i]<= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
}


int main(){
    int arr[] = {1,20 , 4, 32 , 8 , 10 , 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    minOfEverySubarraySizeK(arr , n , k);
    
    return 0;
}