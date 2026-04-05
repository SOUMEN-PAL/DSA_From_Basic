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


void subset(string s , string curr = " " , int i = 0){
    if(i==s.length()){
        cout<<curr<<" ";
        return ; 
    }

    subset(s , curr , i+1);
    subset(s , curr+s[i] , i+1);
}




int main(){
    
    string a = "ABCDEFGHIJKL";

    subset(a);

    
    return 0;
}