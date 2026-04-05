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

int prec(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '/' || ch == '*'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPrefix(string s){
    stack<char> st;
    int n = s.length();
    string res = "";
    for(int i = n-1 ; i>=0 ; i--){
        char x = s[i];
        if((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9')){
            res = res + x;
        }
        else if(x == ')'){
            st.push(x);
        }
        else if(x == '('){
            while(st.top() != ')'){
                res = res + st.top();
                st.pop();
            }
            st.pop(); // removing ( //
        }
        else{
            //its an operator //
            if(x == '^'){
                while(st.empty() != true && prec(x)<=prec(st.top())){
                    res = res + st.top();
                    st.pop();
                }
            }
            else{
                while(st.empty() != true && prec(x)<prec(st.top())){
                    res = res + st.top(); // = nahi ha kyuki jo aa raha ha a woh left to right associativity me obiously age ha //
                    st.pop();
                }
            }
            st.push(x); // we need to push the current operator after all the operations as its remaning and its > top() of the stack //  
        }
    }
    while(st.empty() == false){
        res = res + st.top();st.pop();
    }
    reverse(res.begin() , res.end()); // making it prefix //
    return res;
}

int main(){
    string s = "6/3+2";
    cout<<infixToPrefix(s)<<endl;
    return 0;
}