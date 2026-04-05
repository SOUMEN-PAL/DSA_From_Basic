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

void Selection_Sort(int arr[] , int n){
    for(int i = 0 ; i<n-1 ; i++){
        int min_ind = i;
        for(int j = i+1 ; j<n ; j++){
            if(arr[j]<arr[min_ind]){
                min_ind = j;
            }
        }
        swap(arr[i] , arr[min_ind]);
    }
}



int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Selection_Sort(arr , n);
    for(int i:arr){
        cout<<i<<" ";
    }
    
    return 0;
}