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

bool isMatching(char a , char b){
    if( a == '[' && b == ']'){
        return true;
    }
    else if( a == '(' && b == ')'){
        return true;
    }
    else if(a == '{' && b == '}'){
        return true;
    }
    return false;
}

bool balancedParenthesis(string str){
    stack<char> s;
    
    for(auto x : str){
        if(x == '(' || x == '{' || x == '['){
            s.push(x);
        }
        else{
            if(s.empty() == true){
                return false;
            }
            if(isMatching(s.top() , x) == false){
                return false;
            }
            else{
                s.pop();
            }
        }
    }
    return true;
}

int main(){
    string str = "({{[()[]]}})";
    if(balancedParenthesis(str)){
        cout<<"valid"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }
    return 0;
}