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

int leaftNodes(vector<int> adj[] , int v , int s){
    int leafNode = 0;
    queue<pair<int, int>> q;
    q.push({s, -1}); 
    vector<int> visited(v, false);
    visited[s] = true;

    while (!q.empty()) {
        auto top = q.front();
        int curr = top.first;
        int par = top.second; // Avoid shadowing the parent vector
        q.pop();

        // Check if the current node is a leaf node
        int items = 0;

        for (auto i : adj[curr]) {
            items++;
            if (!visited[i]) {
                q.push({i, curr});
                visited[i] = true;
            }
        }
        if(items == 0){
            leafNode++;
        }
    }
    return leafNode;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int v;
        cin>>v;
        
        vector<int> adj[v+1];

        for(int i = 1 ; i<v ; i++){
            int u , v;
            cin>>u>>v;
            addEdge(adj , u , v);
        }

        v = v+1;

        int asum;
        cin>>asum;

        while(asum--){
            
            int x , y;
            cin>>x>>y;

           
            if(x == y){
                int res = leaftNodes(adj , v , x);
                res = res*res;
                cout<<res<<endl;
            }
            else{
                int r1 = leaftNodes(adj , v , x);
                int r2 = leaftNodes(adj , v , y);
                cout<<r1*r2<<endl;
            }

        }
        
        

    }



    return 0;
}