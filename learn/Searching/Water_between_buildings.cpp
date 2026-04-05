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


int Traping_waterII(int arr[] , int n){
    int l = 0 , h = n-1;
    int res = INT_MIN;
    while(h>l){
        res = max(res , (h-l-1)*min(arr[h] , arr[l]));
        if(arr[h]>arr[l]){
            l++;
        }
        else{
            h--;
        }
    }
    return res;
}



int main(){
    
    return 0;
}