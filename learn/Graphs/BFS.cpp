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


void BFS(vector<int> arr[] , int v , int s){
    bool visited[v+1] = {false};
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int top = q.front();
        q.pop();
        cout<<top<<" ";
        for(int i : arr[top]){
            if(visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }

    }
}


//BFS for adjacency matrix
void BFS(vector<vector<int>> arr , int v , int s){
    bool visited[v+1] = {false};
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int top = q.front();
        q.pop();
        cout<<top<<" ";
        for(int i = 0 ; i < v ; i++){
            if(arr[top][i] == 1 && visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }

    }
}


// BFS in disconnected graph using adjacency list

void bfs(vector<int> arr[] , int v , int s ,  bool visited[]){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        cout<<top<<" ";
        for(auto i : arr[top]){
            if(visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}


void bfs_dis(vector<int> arr[] , int v){
    bool visited[v] = {false};
    for(int i = 0 ; i<v ; i++){
        if(visited[i] == false){
            bfs(arr , v , i , visited);
        }
    }
}

//bfs in disconnected graph using adjacency matrix
void bfs(vector<vector<int>> arr , int v , int s ,  bool visited[]){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        cout<<top<<" ";
        for(int i = 0 ; i < v ; i++){
            if(arr[top][i] == 1 && visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}


void bfs_dis(vector<vector<int>> arr , int v){
    bool visited[v] = {false};
    for(int i = 0 ; i<v ; i++){
        if(visited[i] == false){
            bfs(arr , v , i , visited);
        }
    }
}





int main(){
    int v = 5;
    vector<int> adj[v];
    addEdge(adj , 0 , 1);
    addEdge(adj , 0 , 2);
    addEdge(adj , 1 , 2);
    addEdge(adj , 1 , 3);
    addEdge(adj , 2 , 4);
    addEdge(adj , 3 , 4);



    cout<<"Adjacency List Array Representation of Graph"<<endl;
    printList(adj , v);
    

    BFS(adj , v , 0);


//Creating a disconnected graph
    int V = 10;
    vector<int> ajd_dis[V];
    addEdge(ajd_dis , 0 , 1);
    addEdge(ajd_dis , 0 , 2);
    addEdge(ajd_dis , 3 , 4);
    addEdge(ajd_dis , 5 , 6);
    addEdge(ajd_dis , 6 , 8);
    addEdge(ajd_dis , 7 , 9);
    addEdge(ajd_dis , 8 , 9);

    printList(ajd_dis , V);

    bfs_dis(ajd_dis , V);

    

    return 0;
}