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

int fibo(int n){
    vector<int> fib(n+2);

    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2 ; i<=n ; i++){
        fib[i] = fib[i-1] + fib[i-2]; // the subproblems are being optimised here //
    }

    return fib[n];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int  n;
    cin>>n;
    cout<<fibo(n)<<endl;
    return 0;
}
