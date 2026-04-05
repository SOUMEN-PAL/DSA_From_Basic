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

string ds = "";
void per( string s , int i , int &cnt , int k){
    if(i==s.length()-1){
        cnt++;
        if(cnt == k){
            ds = s;
        }
    }
    else{
        for(int j = i ; j<s.length() ; j++){
            swap(s[i],s[j]);
            per(s , i+1 , cnt , k);
            
        }
    }
}

int main(){
    string s = "123";
    int cnt = 0;
    int k = 3;
    per(s , 0 , cnt , k); 
    cout<<ds<<endl;




    return 0;
}