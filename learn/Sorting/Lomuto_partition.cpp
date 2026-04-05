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


int lomuto_partition(int arr[] , int l , int h , int p){
    swap(arr[p] , arr[h]);
    int pivot = arr[h];
    int i = l-1;
    for(int j = l ; j<=h-1 ; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[i+1] , arr[h]);
    return i+1;
}



int main(){
    int arr[] = {5,12,74,10,5,7,6,2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pivot = lomuto_partition(arr , 0 , n-1 , 1);
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<pivot;
    return 0;
}