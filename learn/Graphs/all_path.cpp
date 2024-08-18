#include<bits/stdc++.h>
using namespace std;

//Directed Graph
void addEdge(vector<int> arr[] , int v , int u){
    arr[v].push_back(u);
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



void DFS(vector<bool> &visited , vector<int> adj[] , int &cnt , int node , int destination){
    if(node == destination){
        cnt++;
        return;
    }

    visited[node] = true;

    for(auto u : adj[node]){
        if(!visited[u]){
            DFS(visited , adj , cnt , u , destination);
        }
    }

    visited[node] = false;

}

int countPaths(int V, vector<int> adj[], int source, int destination) {
    vector<bool> visited(V, false);
    int cnt = 0;
    DFS(visited , adj , cnt , source , destination);
    return cnt;
}


//Itreative DFS solution
int count_paths(int v , vector<int> adj[] , int source , int destination){
    stack<int> st;
    st.push(source);
    int cnt = 0;

    while(!st.empty()){
        int curr = st.top();
        if(curr == destination){
            cnt++;
        }
        st.pop();

        for(auto neighbour : adj[curr]){
            st.push(neighbour);
        }
    }

    return cnt;
}


int main(){
    int v = 5;
    vector<int> adj[v];
    addEdge(adj , 0 , 1);
    addEdge(adj , 0 , 2);
    addEdge(adj , 0 , 4);
    addEdge(adj , 1 , 3);
    addEdge(adj , 1 , 4);
    addEdge(adj , 2 , 4);
    addEdge(adj , 3 , 2);

    cout << "Adjacency List Array Representation of Graph" << endl;
    printList(adj , v);

    cout<<endl;

    cout<<countPaths(v  ,adj , 0 , 4)<<endl;


    return 0;
}