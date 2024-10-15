#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>> arr[] , int v , int u , int wt){
    arr[v].push_back({u , wt});
    arr[u].push_back({v , wt});
}

void printList(vector<vector<int>> adj[], int v) {
    for (int i = 0; i < v; i++) {
        cout << i << " -> ";
        for (auto x : adj[i]) {
            cout << "(" << x[0] << ", " << x[1] << ") ";
        }
        cout << endl;
    }
}


vector<pair<int , pair<int , int>>> shortestPath(vector<vector<int>> adj[] , int v , int S , int P){
    vector<bool> visited(v , false);
    vector<pair<int , pair<int , int>>> ssst;
    priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>>,  greater<pair<int , pair<int , int>>>> pq;

    pq.push({0 , {S , P}});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second.first;
        int wt = it.first;
        int parent = it.second.second;

        if(visited[node] == true){
            continue;
        }

        visited[node] = true;
        ssst.push_back({wt , {node , parent}});

        for(auto &i : adj[node]){
            int neighbor = i[0];
            int weight = i[1];
            if(visited[neighbor] == false){
                pq.push({weight+wt , {neighbor , node}});
            }
        }
    }
    return ssst;
}

void printVector(const vector<pair<int, pair<int, int>>> &vec) {
    for (const auto &item : vec) {
        int weight = item.first;
        int node = item.second.first;
        int parent = item.second.second;
        
        cout << "Weight: " << weight << ", Node: " << node << ", Parent: " << parent << endl;
    }
}


int main(){
    int v = 4;
    vector<vector<int>> adj[v];
    addEdge(adj , 0 , 1 , 2);
    addEdge(adj , 0 , 2 , 2);
    addEdge(adj , 1 , 2 , 1);
    addEdge(adj , 1 , 3 , 2);
    addEdge(adj , 2 , 3 , 3);

    cout << "Adjacency List Array Representation of Graph" << endl;
    printList(adj , v);
    cout<<endl;

    auto shortestGraph = shortestPath(adj , v , 1 , -1);
    printVector(shortestGraph);

    return 0;
}