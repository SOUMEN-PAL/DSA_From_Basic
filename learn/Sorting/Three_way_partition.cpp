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


// Naive solution O(n) and n auxilarry space//
void ThreeWayPartition(int arr[] , int n){
    int temp[n] , c = 0;
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == 0){
            temp[c] = arr[i];
            c++;
        }
    }
    for(int i = 0 ; i<n ; i++){
        if(arr[i]==1){
            temp[c] = arr[i];
            c++;
        }
    }
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == 2){
            temp[c] = arr[i];
            c++;
        }
    }
    for(int i = 0 ; i<n ; i++){
        arr[i] = temp[i];
    }
}

// Efficient solution //
//_________________________Dutch National Flag Algorithm_____________________//
void Three_Sort(int arr[] , int n){
    int lo = 0 , hi = n-1 , mid = 0;
    while(mid<=hi){
        if(arr[mid] == 0){
            swap(arr[lo++] , arr[mid++]);
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid] , arr[hi]);
            hi--;
        }
    }
}



int main(){
    int arr[] = {0,1,2,0,1,2,0,2,2,2,1,0,2,1,0,2,1,0,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    // ThreeWayPartition(arr , n);
    // cout<<"Naive Solution: ";
    Three_Sort(arr , n);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}