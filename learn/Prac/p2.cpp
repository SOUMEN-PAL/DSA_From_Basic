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




int main(){
    
    vector<vector<int>> arr = {
        {10 ,20,30,40},
        {27,29,37,48},
        {15,85,96,34},
        {32,33,39,50}
    };
    sort(arr.begin() , arr.end());
    
    for(auto i : arr){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }




    return 0;
}