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

void max_min(int arr[] , int n , int &max , int &min){

    for(int i = 1 ; i<n ; i++){
        if(arr[i]>arr[max]){
            max = i;
        }

        if(arr[i]<arr[min]){
            min = i;
        }
    }



}


int main(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_in = 0;
    int min_in = 0;
    max_min(arr , n , max_in , min_in);
    cout<<arr[max_in]<<" "<<arr[min_in]<<endl;
    



    return 0;
}