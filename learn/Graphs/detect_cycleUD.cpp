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
 



bool BFS(vector<int> adj[] , int v , vector<bool> &visited , int source){
    queue<pair<int , int>> q;
    q.push({source , -1});
    visited[source] = true;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        
        int vertex = curr.first;
        int parent = curr.second;
        
        for(auto u : adj[vertex]){
            if(visited[u] == false){
                q.push({u , vertex});
                visited[u] = true;
            }
            else if(u != parent){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v , vector<int> adj[]) {
    vector<bool> visited(v , false);
    for(int i = 0 ; i<v ; i++){
        if(visited[i] == false){
            if(BFS(adj , v , visited , i) == true){
                return true;
            }
        }
    }
    return false;
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

    if(isCycle(v , adj)){
        cout << "Cycle is present in the graph" << endl;
    }
    else{
        cout << "Cycle is not present in the graph" << endl;
    }

  
    return 0;
}