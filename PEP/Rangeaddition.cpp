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

vector<int> rangeAddition(vector<vector<int>> v , int n){
    vector<int> res(n , 0);
    int s = v.size();
    for(int i = 0 ; i<s ; i++){
        int start = v[i][0] , end = v[i][1] , value = v[i][2];
        res[start] += value;

        if(end+1 < n){
            res[end] -= -1 * value;
        }

    }
}


int main(){
    
    return 0;
}