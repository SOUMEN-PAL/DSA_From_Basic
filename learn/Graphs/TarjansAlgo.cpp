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


void DFS(vector<int> adj[] , int V , vector<int> &disc , vector<int> &low , vector<vector<int>> &scc , int &time , int src , stack<int> &st , vector<bool> &stMember){
    
    low[src] = disc[src] = ++time;
    st.push(src);
    stMember[src] = true;

    for(auto i : adj[src]){
        if(disc[i] == -1){
            DFS(adj , V , disc , low , scc , time  , i , st , stMember);
            low[src] = min(low[src] , low[i]);
        }
        else if(stMember[i] == true){
            low[src] = min(low[src] , disc[i]);
        }
    }

    if(low[src] == disc[src]){
        
        vector<int> component;
        while(st.top() != src){
            int top = st.top();
            component.push_back(top);
            stMember[top] = false;
            st.pop();            
        }
        component.push_back(st.top());
        stMember[st.top()] = false;
        st.pop();

        scc.push_back(component);
    }
    
}



void SCC(vector<int> adj[] , int V){
    vector<int>disc(V , -1);
    vector<int>low(V , INT_MAX);
    stack<int> st;
    vector<bool> stackMember(V , false);
    vector<vector<int>> scc;
    int time = 0;
    for(int i = 0 ; i <V ; i++){
        if(disc[i] == -1){
            DFS(adj , V , disc , low , scc , time , i , st , stackMember);
        }
    }

    for(auto comp : scc){
        for(auto items : comp){
            cout<<items<<" ";
        }
        cout<<endl;
    }

}



int main(){
    int v = 5;
    vector<int> adj[v];
    addEdge(adj , 1 , 0);
    addEdge(adj , 0 , 2);
    addEdge(adj , 2 , 1);
    addEdge(adj , 0 , 3);
    addEdge(adj , 3 , 4);


    cout << "Adjacency List Array Representation of Graph" << endl;
    printList(adj , v);

    cout<<endl;

    SCC(adj , v);



    return 0;
}