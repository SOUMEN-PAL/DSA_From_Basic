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

int main(){
    
    string a;
    cin>>a;
    string res;
    int x = a.size();
    for(int i = (x-1) ; i>=0 ; i--){
        res = res + a[i];
    }
    if(a==res){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not a plaindrome"<<endl;
    }

    return 0;
}