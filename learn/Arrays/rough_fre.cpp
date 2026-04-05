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
    map<int , int> ans;
    for(int i = 1 ; i<=5 ; i++){
        ans[i] = 0;
    }
    map<int , int> :: iterator it = ans.begin();

    
    for(it ; it!=ans.end() ; it++){
        cout<<it->first<<" "<<it->second<<endl;
  
    } 
    



    return 0;
}