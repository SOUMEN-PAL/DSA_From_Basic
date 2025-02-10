#include<bits/stdc++.h>
using namespace std;



bool isBipartite(vector<vector<int>>& adj ,  vector<int> &color) {
    int V = adj.size();
    queue<int> q;

    
    for(int i = 0 ; i<V ; i++){
        if(color[i] == -1){
            q.push(i);
            color[i] = 0;
            
            
            while(!q.empty()){
                int top = q.front();
                q.pop();
                int new_c = 1 - color[top];
                for(auto i : adj[top]){
                    if(color[i] == -1){
                        q.push(i);
                        
                        color[i] = new_c;
                    }
                    else{
                        if(color[i] == color[top]){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}


int main(){
    int n , m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i = 0 ; i<m ; i++){
        int u , v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<int> color(n+1 , -1);
    bool ans = isBipartite(adj , color);
    
    if(!ans){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(int i = 1 ; i<color.size() ; i++){
            cout<<color[i] + 1<<" ";
        }
    }

    return 0;
}