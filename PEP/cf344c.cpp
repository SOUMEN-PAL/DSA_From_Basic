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
long long int res = 0;
long long sol(long long a, long long b) {
    while (b != 0) {
        res += a / b;
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


int main(){
    long long  a, b;
    cin>>a>>b;

    int x = max(a,b);
    int y = min(a,b);

    auto ans = sol(a , b);
    cout<<res<<endl;

    return 0;
}