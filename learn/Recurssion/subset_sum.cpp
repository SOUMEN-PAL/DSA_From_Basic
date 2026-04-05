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


// return the count of number of subarrays of how many subsets are equals to the sum //
int Nosub(int arr[] , int n , int sum){
    if(n==0){
        if(sum==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    return Nosub(arr , n-1 , sum) + Nosub(arr , n-1 , sum - arr[n-1]);
}



int main(){
    int arr[] = {2,2,4,10};
    int siz = sizeof(arr)/sizeof(arr[0]);
    int sum = 14;
    cout<<Nosub(arr , siz , sum)<<endl;



    return 0;
}