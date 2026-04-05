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
const int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1; // base case: one way to partition 0
    
    // ;iterate over possible parts (1 to n-1, because n itself is not allowed)
    for(int i = 1; i <= n-1; i++){
        for(int j = i; j <= n; j++){
            dp[j] = (dp[j] + dp[j-i]) % MOD;
        }
    }
    cout << dp[n] % MOD;
    return 0;
}