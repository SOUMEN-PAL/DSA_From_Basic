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

string deleteConsecutive2(string str){
    stack<char> s;
    for(int i = 0 ; i<str.length() ; i++){
        if(s.empty() == true){
            s.push(str[i]);
        }
        else{
            if(s.top() == str[i]){
                s.pop();
            }
            else{
                s.push(str[i]);
            }
        }
    }
    string ans = "";
    while(!s.empty()){
        ans = s.top() + ans;
        s.pop();
    }
    return ans;
}


int main(){
    string s = "aaabbaaccd";
    cout<<deleteConsecutive2(s)<<endl;
    return 0;
}