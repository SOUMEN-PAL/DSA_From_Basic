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

void DFS(char a , vector<int> adj[] , vector<bool> &visited){

    visited[a] = true;

    for(auto i : adj[a]){
        if(visited[i] == false){
            DFS(i , adj , visited);
        }
    }

}

bool isCircle(vector<string> &arr){
    int n = arr.size();
    vector<int> adj[26];
    vector<int> in(26 , 0);
    vector<int> out(26 , 0);
    for(int i = 0 ; i<n ; i++){
        string temp = arr[i];
        int u = temp[0] - 'a';
        int v = temp[temp.size() - 1] - 'a';
        adj[u].push_back(v);
        in[v]++;
        out[u]++;
    }


    for(int i = 0 ; i<26 ; i++){
        if(in[i] != out[i]){
            return false;
        }
    }
    vector<bool> visited(26 , false);
    DFS(arr[0][0]-'a' , adj , visited);

    for(int i = 0 ; i<26 ; i++){
        if(in[i] && !visited[i]){
            return false;
        }
    }
    return true;
}


int main(){
    
    return 0;
}