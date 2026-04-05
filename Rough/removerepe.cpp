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


int rem_dup(int arr[] , int n){
    int res = 0;
    for(int i = 0 ; i<n ; i++){
        if(arr[i-1]!=arr[i]){
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}



int main(){
    int arr[] = {1,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a = rem_dup(arr , n);

    for(int i = 0 ; i<a ; i++){
        cout<<arr[i]<<" ";
    }




    return 0;
}