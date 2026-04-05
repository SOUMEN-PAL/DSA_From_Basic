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


// Efficirnt sulution using STL functions //
bool areRotations(string str1 , string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}


int main(){
    string s = "ABCD";
    cout<<s.substr(2)<<endl;
    return 0;
}