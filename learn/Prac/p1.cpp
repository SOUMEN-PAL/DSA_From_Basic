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

void rem_dup(int arr[] , int n){
    int temp[n];
    temp[0] = arr[0];
    int res = 1;

    for(int i = 0 ; i<n ; i++){
        if(temp[res-1]!=arr[i]){
            temp[res] = arr[i];
            res++;
        }
    }


}


void dupp(int arr[] , int n){
    int res = 1;
    for(int i = 1 ; i<n  ; i++){
        if(arr[i]!= arr[i-1]){
            arr[res] = arr[i];
            res++;

        }
    }
}


int main(){
    

	cout<<"hello world"<<endl;

    return 0;
}
