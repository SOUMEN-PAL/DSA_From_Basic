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

int count_ones(int arr[] , int n){
    int low = 0 , high = n-1;
    while(high>=low){
        int mid = (high + low)/2;
        if(arr[mid]==0){
            low = mid+1;
        }
        else{
            if(mid==0 || arr[mid - 1] != arr[mid]){
                return (n-mid);
            }
            else{
                high = mid - 1;
            }
        }
    }
    
    return 0;
    
    
}


int main(){
    int arr[] = {0,0,0,0,0,1,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<count_ones(arr , n)<<endl;
    return 0;
}