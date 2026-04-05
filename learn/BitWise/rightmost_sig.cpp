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
int posOfRightMostDiffBit(int m, int n)
{
    // Your code here
    // int a = max(m,n);
    int msb = log2(m);
    int count=0;
    while(msb>=0){
        unsigned int x=m&1;
        unsigned int y=n&1;
        if(x!=y){
            return count+1;
        }
        
        count++;
        msb--;
        m=m>>1;
        n=n>>1;
    }
    return -1;
}



int main(){
    cout<<posOfRightMostDiffBit(8,0);



    return 0;
}