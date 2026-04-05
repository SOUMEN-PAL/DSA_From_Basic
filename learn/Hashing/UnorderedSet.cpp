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
    unordered_set<int> s;
    s.insert(20);
    s.insert(56);
    auto pos = s.find(20);
    cout<<*pos;
    cout<<s.size()<<endl;

    // unordered_map<string , int> mp;
    // mp["gfg"] = 100;
    // mp.insert({"Hell" , 290});
    // for(auto i : mp){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    return 0;
}