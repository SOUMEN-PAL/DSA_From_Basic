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

int minSwaps(vector<int> &arr){
    int n = arr.size();
    vector<pair<int , int>> res;
    for(int i = 0 ; i<n ; i++){
        res.push_back({arr[i] , i});
    }

    sort(res.begin() , res.end());

    // for(auto i : res){
    //     cout<<i.first<<" "<<i.second<<endl; 
    // }

    int swaps = 0;
    for(int i = 0 ; i<n ; i++){
        auto curr = res[i];
        int index = curr.second;
        int element = curr.first;
        if(index != i){
            swap(res[i] , res[index]);
            swaps++;
            i--;
        }
    }
    return swaps;
}

int main(){

    vector<int> arr = {6 , 4 , 2 , 14 , 8 , 19 , 12 , 16};
    int t = minSwaps(arr);
    cout<<t<<endl;
    return 0;
}