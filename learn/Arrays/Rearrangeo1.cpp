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

void arra(int arr[] , int n){
    for(int i = 0 ; i<n ; i++){
        int x = arr[i]; // storing the current element at the index //
        int y = arr[x]; // the value thath hase to be there but in the combined way to extract the has to be value which is stored as indexing value //
        cout<<x<<" "<<y<<endl;
        arr[i] = x + (y%n)*n;
    }

    for(int i = 0 ; i<n ; i++){
        arr[i] = arr[i]/n;
    }
}


int main(){
    
    int arr[] = {4,0,2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    arra(arr , n);

    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }  


    return 0;
}