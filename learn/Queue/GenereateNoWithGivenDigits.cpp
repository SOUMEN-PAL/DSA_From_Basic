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

string GenerateNo(int n){
    string res = "";
    queue<string> q;
    q.push("5");
    q.push("6");
    for(int count = 0 ; count<n ; count++){
        string curr = q.front();
        res = res + curr;
        q.pop();
        q.push(curr + "5");
        q.push(curr + "6");
    }
    return res;
}

int main(){
    cout<<GenerateNo(40)<<endl;
    return 0;
}