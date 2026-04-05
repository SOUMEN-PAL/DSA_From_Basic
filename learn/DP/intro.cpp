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
typedef long long ll;
const ll INF = 1LL << 60;


int knapSack(vector<int> val , vector<int> weight , int W , int i){
    if(i == val.size() || W == 0){
        return 0;
    }

    if(weight[i] > W){
        return knapSack(val , weight , W , i+1);
    }
    else{
        return max(
            val[i] + knapSack(val , weight , W - weight[i] , i+1),
            knapSack(val , weight , W , i+1)
        );
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}