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

int Upper_bound(int arr[] , int n , int x){
           int low  = 0;
           int high = n-1;
           int ans = -1;
           while(low <= high){
               int mid = low + (high-low)/2;
               if(arr[mid] <= x){
                   ans = mid;
                   low = mid+1;
               }
               else{
                   high = mid-1;
               }
           }
           
           return ans;
}



int main(){

    int arr[] = { 1, 2, 7, 10, 10, 12, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;

    cout<<Upper_bound(arr , n , x)<<endl;

    return 0;
}