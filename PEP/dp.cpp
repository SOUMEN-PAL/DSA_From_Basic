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

//rat in a maze uisng DP

int ratInMaze(int n , int m , int **arr){
    int dp[n][m];
    memset(dp , 0 , sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(arr[i][j] == 0){
                if(i>0){
                    dp[i][j] += dp[i-1][j];
                }
                if(j>0){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
    }
    return dp[n-1][m-1];
}

int main(){
    int n , m;
    cin>>n>>m;
    int **arr = new int*[n];
    for(int i = 0 ; i<n ; i++){
        arr[i] = new int[m];
        for(int j = 0 ; j<m ; j++){
            cin>>arr[i][j];
        }
    }
    cout<<ratInMaze(n , m , arr);
    return 0;
}
