#include<bits/stdc++.h>
using namespace std;

// Adjency matrix
vector<vector<int>> graphInput(int n, int m){
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    return graph;
}

// Adjency list
vector<vector<int>> graphInput(int n, int m){
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}




int main(){
    
    return 0;
}