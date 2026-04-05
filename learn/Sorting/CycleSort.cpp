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


void cycle_sort(int arr[] , int n){
    for(int cs = 0 ; cs<n-1 ; cs++){
        int item = arr[cs];
        int pos = cs;
        for(int i = cs+1 ; i<n ; i++){
            if(arr[i]<item){
                pos++;
            }
        }
        swap(item , arr[pos]);
        while(pos != cs){
            pos = cs;
            for(int i = cs + 1 ; i<n ; i++){
                if(arr[i]<item){
                    pos++;
                }
            }
            swap(item , arr[pos]);
        }
    }
}

int main(){
    int arr[] = {20 , 40 , 50 , 10 , 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cycle_sort(arr , n);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}