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

int check_bits(int pattern , int arr[] , int n){
    int count=0;
    for(int i = 0 ; i < n ; i++){
        if((pattern & arr[i]) == pattern){
            count++;
        }
    }
    return count;
}


int max_andvalue(int arr[] , int n){
    int res=0 , count;
    for(int bit = 31 ; bit>=0 ; bit-- ){
        count = check_bits((res|(1<<bit)) , arr , n );

        if(count>=2){
            res = res|(1<<bit);
        }

    }
    return res;
}


int main(){

    int arr[] = {4,8,16,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<max_andvalue(arr , n)<<endl;

    




    return 0;
}