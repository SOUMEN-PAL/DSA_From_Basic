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

void bfs(vector<vector<int>> &adj , vector<bool> &visted , int node){
    queue<int> q;
    q.push(node);
    visted[node] =  true;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        for(auto i : adj[curr]){
            if(visted[i] == false){
                q.push(i);
                visted[i] = true;
            }
        }
    }
}


int main(){
    int n , m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    vector<bool> visited(n , false);
    
    for(int i = 0 ; i<m ; i++){
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> edg;
    for(int i = 1  ; i<=n ; i++){
        if(visited[i] == false){
            edg.push_back(i);
            bfs(adj , visited , i);
        }
    }


    int ansSize = edg.size();
    cout<<ansSize-1<<endl;

    for(int i = 0 ;i<ansSize-1 ; i++){
        cout<<edg[i]<<" "<<edg[i+1]<<endl;
    }


    
    return 0;
}