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

int prefixEvaluation(string s){
    stack<int> st;
    int n = s.length();
    for(int i = n - 1 ; i>= 0 ; i--){
        char x = s[i];
        if(x == ' '){
            continue;
        }
        else if(isdigit(x)){
            int num = 0;
            while(isdigit(s[i])){
                num = (num*10) + (s[i]-'0');
                i++;
            }
            i--;
            st.push(num);
        }
        else{
            int op1 = st.top();st.pop();
            int op2 = st.top();st.pop();

            int res;
            switch (x)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op2 - op1;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '*':
                res = op2*op1;
                break;
            case '^':
                res = pow(op1 , op2);
                break;
            default:
                break;
            }
            st.push(res);
        }
    }
    return st.top();
}


int main(){
    string s = "+ / 6 3 2";
    cout<<prefixEvaluation(s)<<endl;
    return 0;
}