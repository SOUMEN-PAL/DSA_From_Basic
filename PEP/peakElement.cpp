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

int PeakElement(int arr[] , int n){
    int low = 0 , high = n - 1;

    while(high>=low){
        int mid = (high + low)/2;
        if((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n-1 || arr[mid + 1]<= arr[mid])){
            return arr[mid];
        }
        else if(mid>0 && arr[mid - 1]>=arr[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return -1;
}



int main(){
    int arr[] = {10,20,10,40,10 , 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    *(arr+3) = 3;
    cout<<arr[3]<<endl;
    

    return 0;
}