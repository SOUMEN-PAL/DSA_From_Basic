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


//comparater for priority queue
class myComp{
    public:
    bool operator()(vector<int> &a , vector<int> &b){
        return a[1] < b[1];
    }
};

void BFS(vector<vector<int>>& edges , vector<int> &nums , vector<bool> visited , int largestLength){
    
}


vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
    priority_queue<vector<int> , vector<vector<int>> , myComp> pq(edges.begin() , edges.end());

    auto tp = pq.top();
    
    int largestLength = tp[2];


}


int main(){
    
    return 0;
}