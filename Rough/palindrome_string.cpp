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

bool ispalindrome(string &str , int start , int end){
    if(start>=end){
        return true;
    }

    return (str[start]==str[end] && ispalindrome( str , start+1 , end-1));
}


int main(){
    string s = "lol";
    int st = 0 , e = s.length()-1;
    if(ispalindrome(s , st , e)){
        cout<<s<<" is a plindrome"<<endl;
    }
    else{
        cout<<"not a palindrome"<<endl;
    }

    return 0;
}