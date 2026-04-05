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

void helper(vector<int> arr, int ind, vector<int>& ds, vector<vector<int>>& res) {
    if (ind == arr.size()) {
        res.push_back(ds);
        return;
    }

    helper(arr, ind + 1, ds, res);
    ds.push_back(arr[ind]);
    helper(arr, ind + 1, ds, res);
    ds.pop_back();
}

vector<vector<int>> subsets(vector<int> arr, int n) {
    vector<int> ds;
    vector<vector<int>> res;
    helper(arr, 0, ds, res);
    return res;
}


void dsnt_helper
(
    vector<int> arr,
    int ind,
    vector<int>& ds,
    vector<vector<int>>& res
) {

    res.push_back(ds);
    for (int i = ind; i < arr.size();i++) {
        if(i != ind && arr[i] == arr[i-1]){
            continue;
        }
        ds.push_back(arr[i]);
        dsnt_helper(arr, i + 1, ds, res);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> dsnt_subset
(
    vector<int> arr,
    int n
) {
    vector<int> ds;
    vector<vector<int>> res;
    dsnt_helper(arr , 0 ,ds , res);
    return res;
}


int main() {
    vector<int> arr = { 1,2,3,2,5,6 };
    int n = arr.size();
    auto answer = dsnt_subset(arr, n);

    for (auto i : answer) {
        for (auto ele : i) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}