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

void print(string s){
    int count[26] = {0}; // Frequnecy storing array //
    for(int i = 0 ; i<s.length() ; i++){
        count[s[i] - 'a']++;
    }
    for(int i = 0 ; i<26 ; i++){
        if(count[i]>0){
            cout<<char(i +'a')<<" "<<count[i]<<endl;
        }
    }
}


int main(){
    string s = "geeksforgeeks";
    print(s);
    return 0;
}