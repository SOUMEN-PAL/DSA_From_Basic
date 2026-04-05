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

bool myComp(pair<int , int> &a , pair<int , int> &b){
    return (a.second < b.second);
}

int maxActivities(vector<pair<int , int>> arr , int n){
    sort(arr.begin() , arr.end() , myComp);
    int prev = 0;
    int res = 1;
    for(int curr = 1 ; curr<n ; curr++){
        if(arr[curr].first >= arr[prev].second){
            res++;
            prev = curr;
        }
    }
    return res;

}



int main(){
    vector<pair<int , int>> arr = {make_pair(1,2) , make_pair(2,3) , make_pair(3 , 4) , make_pair(5 , 6)};
    int n  = arr.size();

    int ans = maxActivities(arr , n);

    cout<<"The answer is: "<<ans<<endl;
    
    return 0;
}