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
    vector<vector<int>> a;
    vector <int> b;
    b.push_back(1);
    a.push_back(b);
// we are not able to directly push back in a 2d array so as there is a vector in a vector so its bette to make a vector andd push back it to a another array which a 2d array//
    cout<<a[0][0];   


    return 0;
}