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

void permu(string s , int i = 0){
    if(i==s.length()-1){
        cout<<s<<" ";
    }

    else{
        for(int j = i  ; j<s.length() ; j++){
            swap(s[i],s[j]);
            permu(s , i+1);
            swap(s[i],s[j]);
        }
    }
}

int main(){
    permu("ABC");
    return 0;
}