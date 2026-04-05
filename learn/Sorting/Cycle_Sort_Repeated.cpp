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

int Minimum_Swaps(int arr[], int n){
    int Swap_count = 0;
    for(int cycle_start = 0 ; cycle_start<n-1 ; cycle_start++){
        int item = arr[cycle_start];
        int pos = cycle_start;
        for(int i = cycle_start + 1 ; i<n ; i++){
            if(arr[i]<item){
                pos++;
            }
        }
        if(pos == cycle_start){
            continue;
        }
        if(arr[pos] == item){
            pos++;
        }
        swap(item , arr[pos]);
        Swap_count++;
        while(cycle_start != pos){
            pos = cycle_start;
            for(int i = cycle_start + 1 ; i<n ; i++){
                if(arr[i]<item){
                    pos++;
                }
            }
            if(arr[pos] == item){
                pos++;
            }
            swap(item , arr[pos]);
            Swap_count++;
        }
    }
    return Swap_count;
}

int main(){
    int arr[] = {20 , 40 , 10 , 50 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Minimum_Swaps(arr , n)<<endl;
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}