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

int gcd(int a , int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b , a%b);
    }
}

int num(int n){
    int hcf = 1;
    int res = 1;
    for(int i = 2 ; i<=n ; i++){
        hcf = gcd(i,res);
        res = res*i;
    }
}

int main(){
    



    return 0;
}