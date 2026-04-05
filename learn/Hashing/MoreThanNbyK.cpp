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

void nBYkOccurences(int arr[] , int n , int k)
{
    map<int , int> mp;
    for(int i = 0 ; i<n ; i++){
        if(mp.find(arr[i]) != mp.end()){
            mp[arr[i]]++;
        }
        else if(mp.size() <= k-1)
        {
            mp.insert({arr[i] , 1});
        }
        else{
            for(auto x : mp){
                x.second--;
                if(x.second == 0){
                    mp.erase(x.first);
                }
            }
        }
    }

    // Verification phase //
    for(auto x : mp){
        int count = 0;
        for(int i = 0 ; i<n ; i++){
            if(x.first == arr[i]){
                count++;
            }
        }
        if(count > n/k){
            cout<<x.first<<endl;
        }
    }
}


int main(){
    
    return 0;
}