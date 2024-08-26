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
    cout<<endl;
}


bool DFSRec(vector<int> adj[] , int source , vector<bool> &visited , vector<bool> &recSt){
    visited[source] = true;
    recSt[source] = true;

    for(auto u : adj[source]){
        if(visited[u] == false && DFSRec(adj , u , visited , recSt)){
            return true;
        }
        else if(recSt[u] == true){
            return true;// found a back edge
        }
    }

    recSt[source] = false;
    return false;
}



bool detectLoop(vector<int> adj[] , int v){
    vector<bool> visited(v , false);
    vector<bool> recSt(v , false);

    for(int i = 0 ; i<v ; i++){
        if(visited[i] == false){
            if(DFSRec(adj , i , visited , recSt)){
                return true;
            }
        }
    }
    return false;
}





int main(){
    int v = 6;
    vector<int> adj[v];
    addEdge(adj , 0 , 1);
    addEdge(adj , 1 , 2);
    addEdge(adj , 2 , 3);
    addEdge(adj , 3 , 4);
    addEdge(adj , 4 , 5);
    addEdge(adj , 5 , 5);

    cout << "Adjacency List Array Representation of Graph" << endl;
    printList(adj , v);

    cout<<detectLoop(adj , v)<<endl;

    return 0;
}