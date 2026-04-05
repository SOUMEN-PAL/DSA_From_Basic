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

void move(int arr[] , int n){
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        if(arr[i]!=0){
            swap(arr[i] , arr[count]);
            count++;
        }
    }


    cout<<"The new array is: ";
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



int main(){

    int arr[] = {1,0,3,0,0,0,8,6,0,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    move(arr , n);
    
    return 0;
}