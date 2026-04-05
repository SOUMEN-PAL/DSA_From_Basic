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

void previousGreater(int arr[] , int n){
    stack<int> s;
    s.push(arr[0]);
    for(int i = 0 ; i<n ; i++){
        while(s.empty() == false && s.top() <= arr[i]){
            s.pop();
        }

        int p = s.empty()?-1 : s.top();
        cout<<p<<" ";
        s.push(arr[i]);
    }
}

int main(){
    int arr[] = {13 , 15 , 12 , 14 , 16 , 8 , 6 , 4 ,10 , 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    previousGreater(arr , n);
    return 0;
}