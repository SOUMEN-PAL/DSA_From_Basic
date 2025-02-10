#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    
    for(int i = 0 ; i<m ; i++){
        int u , v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool found = false;
    queue<int> q;
    q.push(1);
    vector<bool> visited(n+1 , false);
    vector<int> parent(n+1 , 0);
    parent[1] = -1;
    visited[1] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == n){
            found =true;
            break;
        }

        for(auto i : adj[curr]){
            if(visited[i] == false){
                visited[i] = true;
                parent[i] = curr;
                q.push(i);
            }
        }
    }

    if(!found){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int> path;
        int k = n;
        while(k != -1){
            path.push_back(k);
            k = parent[k];
        }
        reverse(path.begin() , path.end());
        cout<<path.size()<< endl;
        for(auto i : path){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}