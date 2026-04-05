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


// naive approach //

int max_one(int arr[] , int n){
    int res = 0;
    for(int i =0 ; i<n ; i++){
        int curr = 0;
        for(int j = i ; j<n ; j++){
            if(arr[j]==1){ //  here we are checking for all the upcomming values or consecutive ones //
                curr++;
            }
            else{
                break;
            }
        }

        res = max(res , curr);
    }
    return res;
    
}

// efficient solution //
int one(int arr[] , int n){
    int res = 0 , curr = 0;;
    for(int i = 0 ; i<n ; i++){
        if(arr[i]!=1){
            curr=0;
        }
        else{
            curr++;
            res = max(res , curr);
        }
    }
    return res;
}




int main(){
    int arr[] = {1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<max_one(arr , n)<<"  "<<one(arr , n)<<endl;

    return 0;
}