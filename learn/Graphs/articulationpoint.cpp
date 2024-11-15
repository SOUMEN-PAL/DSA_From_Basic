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



void DFS(vector<int> adj[] , vector<bool> &visited , vector<bool> &ap , vector<int> &disc , vector<int> &parent , vector<int> &low , int src , int time , int V){

    int children = 0;
    visited[src] = true;

    disc[src] = low[src] = ++time;

    for(auto i : adj[src]){
        if(visited[i] == false){
            children++;
            parent[i] = src;

            DFS(adj , visited , ap , disc , parent , low , i , time , V);

            low[src] = min(low[src] , low[i]);

            //if root node//
            if(parent[src] == -1 && children > 1){
                ap[src] = true;
            }

            if(parent[src] != -1 && low[i] >= disc[src]){
                ap[src] = true;
            }
            // as starting me 0 , 0 hi rahega so wehen i check for low src > disc src then it would be going wrong;

        }
        else if(parent[src] != i && visited[i] == true){
            low[src] = min(low[src] , disc[i]); // yeh bandha visited kyu ha kyuki yeh pehele se hi discovered ha
        }


    }
    
}

void articulationPoint(vector<int> adj[] , int V){
    vector<bool> visited(V , false);
    vector<bool> ap(V , false);
    vector<int> discovery(V , INT_MAX);
    vector<int> parent(V , -1); // to get the parent of a desired node to get the solution in the undirective graph
    vector<int> low(V , INT_MAX);

    for(int i = 0 ; i<V ; i++){
        if(visited[i] == false){
            DFS(adj , visited , ap , discovery , parent , low , i , 0 , V);
        }
    }


    for(int i = 0 ; i<V ; i++){
        if(ap[i]){
            cout<<i<<" ";
        }
    }

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

    cout<<endl;

    articulationPoint(adj , v);
    cout<<endl;

    return 0;
}