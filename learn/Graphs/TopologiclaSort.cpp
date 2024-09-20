#include<bits/stdc++.h>
using namespace std;

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



//Topo sort using the bfs and and the kans algo
vector<int> TopoSort(vector<int> adj[] , int v){
    vector<int> in(v , 0);
    for(int i = 0 ; i<v ; i++){
        for(auto u : adj[i]){
            in[u]++;
        }
    }

    queue<int> q;
    vector<int> res;

    for(int i = 0 ; i<v ; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        res.push_back(curr);
        for(auto i : adj[curr]){
            in[i]--;
            if(in[i] == 0){
                q.push(i);
            }
        }
    }
    return res;
}




void DFS(vector<int> adj[], int u,stack<int> &st, bool visited[]) 
{ 	
    visited[u]=true;
    
    for(int v:adj[u]){
        if(visited[v]==false)
            DFS(adj,v,st,visited);
    }
    st.push(u);
}


void topologicalSort(vector<int> adj[], int V) 
{ 
    bool visited[V]; 
	for(int i = 0;i<V; i++) 
		visited[i] = false;
	stack<int> st;
    
    for(int u=0;u<V;u++){
        if(visited[u]==false){
            DFS(adj,u,st,visited);
        }
    }
    
    while(st.empty()==false){
        int u=st.top();
        st.pop();
        cout<<u<<" ";
    }

}


int main(){
    int v = 5;
    vector<int> adj[v];
    addEdge(adj , 0 , 3);
    addEdge(adj , 0 , 2);
    addEdge(adj , 1 , 3);
    addEdge(adj , 2 , 3);
    addEdge(adj , 1 , 4);

    auto res = TopoSort(adj , v);

    for(auto i : res){
        cout<<i<<" ";
    }

    cout<<endl;

    topologicalSort(adj , v);


    return 0;
}