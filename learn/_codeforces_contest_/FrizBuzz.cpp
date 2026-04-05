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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        ll cnt = n/15;
        ll cnt2 = n%15;
        ll res = cnt * 3;

        ll extra = min((ll)3 , cnt2 + 1);
        ll ans = res + extra;
        cout<<ans<<endl;
    }
    
    return 0;
}