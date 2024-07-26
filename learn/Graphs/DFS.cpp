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
    cout<<endl;
}


//DFS on adjacency list
void DFS_rec(vector<int>adj[] , vector<bool> &visited , int s){
    visited[s] = true;
    cout<<s<<" ";
    for(auto u : adj[s]){
        if(visited[u]==false){
            DFS_rec(adj , visited , u);
        }
    }
}

void DFS(vector<int> adj[] , int s , int v){
    vector<bool> visited(v , false);
    for(int i =  0 ; i<v ; i++){
        if(visited[i] == false){
            DFS_rec(adj , visited , i); // for disconnectd graph
        }
    }
    cout<<endl<<endl;
}


void addEdge(vector<vector<int>> &adjMatrix , int v , int u){
    adjMatrix[v][u] = 1;
    adjMatrix[u][v] = 1;
}


void printMatrix(vector<vector<int>> &adjMatrix){
    for(int i = 0 ; i < adjMatrix.size() ; i++){
        for(int j = 0 ; j < adjMatrix[i].size() ; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

void DFS_rec(vector<vector<int>> &adjMatrix , vector<bool> &visited ,int v , int s){
    visited[s] = true;
    cout<<s<<" ";
    for(int i = 0 ; i<v ; i++){
        if(adjMatrix[s][i] == 1 && visited[i] == false){
            DFS_rec(adjMatrix , visited , v , i);
        }
    }
    
}

void DFS(vector<vector<int>> &adjMatrix , int s , int v){
    vector<bool> visited(v , false);
    for(int i = 0 ; i<v ; i++){
        if(visited[i] == false){
            DFS_rec(adjMatrix , visited , v , i);
        }
    }
    cout<<endl;
}


int main(){
    int v = 4;
    vector<int> adj[v];
    addEdge(adj , 0 , 1);
    addEdge(adj , 0 , 2);
    addEdge(adj , 1 , 2);
    addEdge(adj , 1 , 3);

    cout << "Adjacency List Array Representation of Graph" << endl;
    printList(adj , v);

    DFS(adj , 0 , v);


    v = 4;
    vector<vector<int>> adjMatrix(v , vector<int>(v , 0));
    addEdge(adjMatrix , 0 , 1);
    addEdge(adjMatrix , 0 , 2);
    addEdge(adjMatrix , 1 , 2);
    addEdge(adjMatrix , 1 , 3);
    
    cout << "Adjacency Matrix Representation of Graph" << endl;

    printMatrix(adjMatrix);


    DFS(adjMatrix , 0 , v);

    return 0;
}