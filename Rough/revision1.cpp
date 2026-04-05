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

int T[256];
void look(){
    T[0]=0;
    for(int i = 1 ; i<256 ; i++){
        T[i] = T[i&(i-1)]+1;
    }


}

int count_setbit(int n){
    look();

    return(T[n&255]+
        T[(n>>8)&255]+
        T[(n>>16)&255]+
        T[n>>24]);
}


int main()
{
    cout<<count_setbit(5);
    return 0;
}