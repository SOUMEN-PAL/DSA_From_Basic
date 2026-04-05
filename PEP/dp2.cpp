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

string smallestNumber(int s, int d) {
        // code here
        if(s == 0){
            if(d == 1){
                return "0";
            }
            else{
                return "-1";
            }
        }
        if(s > 9*d){
            return "-1";
        }
        string res = "";
        s = s - 1;
        for(int i = d-1; i > 0; i--){
            if(s > 9){
                res = "9" + res;
                s = s - 9;
            }
            else{
                res = to_string(s) + res;
                s = 0;
            }
        }
        res = to_string(s+1) + res;
        return res;
    }


int main(){

    cout<<smallestNumber(9,2)<<endl;
    
    return 0;
}