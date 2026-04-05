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

int rope_cut(int n , int a , int b , int c){
    if(n==0){
        return 0;
    }
    if(n<0){
        return -1;
    }

    int res = max(rope_cut(n-a , a , b, c),max(rope_cut(n-b , a , b , c) , rope_cut(n-c , a , b, c)));
    // thsi question teaches how benificial is overhead //
    if(res==-1){
        return -1;
    }

    return res+1;
}


int main(){
    int n = 5 , a = 2 , b = 5 , c = 1;

    cout<<"The maximum ropes are: "<<rope_cut(n , a , b, c)<<endl;

    return 0;
}