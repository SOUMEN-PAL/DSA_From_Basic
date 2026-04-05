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

int largest(int arr[] , int n){
    int temp=0;
    for(int i = 0 ; i<n  ;i++){
        if(arr[i]>temp){
            temp = arr[i]; // naive approach //
        }
        else{
            temp = temp;
        }
    }
    return temp;
}


int main(){
    int arr[] = {1,2,3,478,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<largest(arr , n)<<endl;



    return 0;
}