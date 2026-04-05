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

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int> dist(V , 1e8);
    dist[src] = 0;
    
    for(int i = 0 ; i<V-1 ; i++){
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            
            if(dist[u] != 1e8 && dist[v] > wt + dist[u]){
                dist[v] = wt+dist[u];
            }
        }
    }
    
    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        int wt = i[2];
        
        if(dist[u] != 1e8 && dist[v] > wt + dist[u]){
            return {-1};
        }
    }
    
    return dist;
}



int main(){
    
    return 0;
}