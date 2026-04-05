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

int Repeated_element(int arr[] , int n){
    int slow = arr[0]+1 , fast = arr[0]+1;
    do{
        slow = arr[slow]+1;
        fast = arr[arr[fast]+1]+1;
    }while(slow != fast);

    slow = arr[0]+1;
    while(slow != fast){
        slow = arr[slow]+1;
        fast = arr[fast]+1;
    }

    return slow-1;
}




int main(){
    int arr[] = {0 , 1 , 2 , 4, 3 , 5 , 6 , 7  , 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Repeated_element(arr , n)<<endl;
    
    return 0;
}