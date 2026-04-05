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
#define mod 1000000007
long long power(int N,int R)
{
    if(R==0){
      return 1;
    }
    if(N==1){
      return 1;
    }
  long long res=power(N,R/2)%mod;
  if(R%2==0){
      return (res*res)%mod;
  }
  else{
      return (((res*res)%mod)*N)%mod;
  }
    
}

int main(){
    
    return 0;
}


