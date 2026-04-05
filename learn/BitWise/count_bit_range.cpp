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

int count_inrange(int n){
    if(n==0 || n==1){
        return n;
    }
    int msb = floor(log2(n));
    return (msb*(1<<msb-1)) + ((n-(1<<msb))+1) + count_inrange(n-(1<<msb)); 
}


int main()
{
    cout<<count_inrange(4);



    return 0;
}