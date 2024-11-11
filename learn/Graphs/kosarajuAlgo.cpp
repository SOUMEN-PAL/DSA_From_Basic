#include<bits/stdc++.h>
using namespace std;


//Directed graph
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


void DFS(vector<int> adj[] , int v , stack<int> &st , vector<bool> &visited){
    visited[v] = true;
    for(auto u : adj[v]){
        if(visited[u] == false){
            DFS(adj , u , st , visited);
        }
    }
    st.push(v);
}  


void kosaRaju(vector<int> adj[] , int v , int s){
    vector<bool> visited(v , false);
    stack<int> finishTime;
    DFS(adj , s , finishTime , visited);
    //Reverse the graph how?? TransPose??But I have adjacenty list :Solution create a new graph
    vector<int> g2[v];

    for(int i = 0 ; i < v ; i++){
        for(auto u : adj[i]){
            addEdge(g2 , u , i);
        }
    }

    fill(visited.begin() , visited.end() , false);
    while(!finishTime.empty()){
        int top = finishTime.top();
        finishTime.pop();
        
            if(visited[top] == false){
                stack<int> st;
                st.push(top);

                while(st.empty() == false){
                    auto curr = st.top();
                    cout<<curr<<" ";
                    st.pop();
                    visited[curr] = true;
                    for(auto j : g2[curr]){
                        if(visited[j] == false){
                            st.push(j);
                            visited[j] = true; // Dont forget to mark the unvisited to visited;
                        }
                    }
                }
                cout<<endl;
            }
        
    }

     
}





int main(){
    int v = 5;
    vector<int> adj[v];
    addEdge(adj , 0 , 1);
    addEdge(adj , 1 , 2);
    addEdge(adj , 2 , 0);
    addEdge(adj , 1 , 3);
    addEdge(adj , 3 , 4);
    addEdge(adj , 4 , 3);

    cout << "Adjacency List Array Representation of Graph" << endl;
    printList(adj , v);
    cout<<endl;
    kosaRaju(adj , v , 0);

    return 0;
}