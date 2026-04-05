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

// c style passing 2d array //
void print(int **arr , int m , int n){
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            cout<<arr[i][j]<<" "; 
        }
        cout<<endl;
    }
}

// using aray of pointers //



int main(){
    int **arr;
    int m = 3 , n = 2;
    arr = new int *[m];
    for(int i = 0 ; i<m ; i++){
        arr[i] = new int[n];
        for(int j = 0 ; j<n ; j++){
            arr[i][j] = i;
        }
    }

    print(arr , m , n);
    return 0;
}