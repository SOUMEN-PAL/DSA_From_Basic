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
    int t;
    cin>>t;
    while(t--){
        int cntFibo = 0;
        int a , b , d , e;
        cin>>a>>b>>d>>e;

        //need to find c so that a + b = c or b + c = d or c + d = e
        int c = d - b;
        
        if(a+b == c){
            cntFibo++;
        }
        if(b+c == d){
            cntFibo++;
        }
        if(c+d == e){
            cntFibo++;
        }
        cout<<cntFibo<<endl;
    }


    return 0;
}