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

    return 0;
}