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

int subset_sum(int arr[] , int n , int sum){
    if(n==0){
        if(sum==0){
            return 1;

        }
        else{
            return 0;
        }
    }

    return subset_sum(arr , n-1 , sum) + subset_sum(arr  , n-1 , sum-arr[n-1]);
}


int main(){

    int arr[] = {30 , 10 , 20};
    int n = sizeof(arr)/sizeof(arr[0]) ;
    int sum = 30;
    cout<<subset_sum(arr , n , sum)<<endl;
    
    return 0;
}