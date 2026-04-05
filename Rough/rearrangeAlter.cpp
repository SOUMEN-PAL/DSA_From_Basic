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

void alter(int arr[] , int n){
    sort(arr, arr+n);
    int maxi = arr[n-1]+1;
    int max = n-1;
    int min = 0;

    for(int i = 0 ; i<n ; i++){
        if(i%2==0){
            arr[i] = arr[i] + ((arr[max]%maxi) * maxi);
            max--;
        }
        else{
            arr[i] = arr[i] + ((arr[min]%maxi)*maxi);
            min++;
        }
    }

    for(int i = 0 ; i< n ; i++){
        arr[i] = arr[i]/maxi;
    }
}


int main(){
    int arr[] = {1,4,5,6,7,8,3,67,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    alter(arr,n);
    cout<<"{ ";
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"}";

    return 0;
}