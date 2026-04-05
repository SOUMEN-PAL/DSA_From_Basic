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

int countDistinct (int arr[], int n, int k)
{
    int res = INT_MIN;
    map<int , int> mp;
    for(int i = 0 ; i<k ; i++)
    {
        mp[arr[i]]++;
    }
    res = max(res , (int)mp.size());
    for(int i = k ; i<n ; i++)
    {
        mp[arr[i-k]] -= 1;
        if(mp[arr[i-k]] == 0)
        {
            mp.erase(arr[i-k]);
        }
        mp[arr[i]]++;
        res = max(res , (int)mp.size());
    }
    return res;
}


int main(){
    int arr[] = {1,2,2,3,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<countDistinct(arr , n , k);
    
    return 0;
}