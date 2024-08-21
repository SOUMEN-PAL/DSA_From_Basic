#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> arr[] , int v , int u){
    arr[v].push_back(u);
    arr[u].push_back(v);
}


void printList(vector<int> adj[] , int v){
    for(int i = 0 ; i < v ; i++){
        cout << i << " -> ";
        for(auto x : adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}

vector<int> shortest_distence(vector<int> adj[] , int source , int v){
    vector<bool> visited(v , false);
    vector<int> dist(v , INT_MAX);
    dist[source] = 0;
    queue<int> q;
    visited[source] = true;
    q.push(source);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto i : adj[curr]){
            if(visited[i] == false){
                q.push(i);
                dist[i] = dist[curr] + 1;
                visited[i] = true;
            }
        }
    }
    return dist;
}


int main(){
    int v = 4;
    vector<int> adj[v];
    addEdge(adj , 0 , 1);
    addEdge(adj , 0 , 2);
    addEdge(adj , 1 , 2);
    addEdge(adj , 1 , 3);
    addEdge(adj , 2 , 3);


    cout << "Adjacency List Array Representation of Graph" << endl;
    printList(adj , v);


    vector<int> dist = shortest_distence(adj , 0 , v);
    cout << "Shortest Distence from source 0 to all other nodes" << endl;
    for(int i = 0 ; i < v ; i++){
        cout << i << " -> " << dist[i] << endl;
    }


    return 0;
}