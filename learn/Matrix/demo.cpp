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



int main(){
    pair<int , int> arr[4][4];
    for(int i = 0 ; i<4 ; i++){
        for(int j = 0 ; j<4 ; j++){
            arr[i][j] = make_pair(i , j);
        }
    } 
    for(int i = 0 ; i<4 ; i++){
        for(int j = 0 ; j<4 ; j++){
            cout<<"{"<<arr[i][j].first<<","<<arr[i][j].second<<"} ";
        }
        cout<<endl;
    } 
    return 0;
}