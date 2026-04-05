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

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(30);
    s.push(40);

    cout<<s.size()<<endl;

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    


    return 0;
}