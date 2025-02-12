#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

struct Edge{
    int u;
    int v;
    ll wt;
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int n,m,a,b;
    ll c;
    cin>>n>>m;

    vector<Edge> edges(m);
    

    for(int i = 0 ; i<m ; i++){
        cin>>a>>b>>c;
        edges[i].u = a;
        edges[i].v = b;
        edges[i].wt = -c;
    }

    vector<ll> dp(n+1 , INF);

    // current length from source 1 is 0;
    dp[1] = 0;


    //normal bellman ford
    for(int i = 1; i< n ; i++){
        for(auto &e : edges){
            if(dp[e.u] != INF && dp[e.u] + e.wt < dp[e.v]){
                dp[e.v] = dp[e.u] + e.wt;
            }
        }
    }

    //Negative cycle
    vector<bool> updated(n+1, false);
    for (const auto &e : edges) {
        if (dp[e.u] != INF && dp[e.u] + e.wt < dp[e.v]) {
            updated[e.v] = true; // marking all the updated nodes for future bfs reference
        }
    }

    //yaha tak toh ho gaya tha //


    //now if the updated nodes is reaching to destination we would be having trouble

    // as I didnt not created a graph jus the edges for bellman ford so we need the graph
    // and for BFS we do not need weights///

    vector<vector<int>> adj(n+1);

    for(const auto &e : edges){
        adj[e.u].push_back(e.v);
    }

    queue<int> q;
    vector<bool> visited(n+1 , false);

    for(int i = 1 ; i<n+1 ; i++){
        if(updated[i]){
            q.push(i);
            visited[i] = true;
        }
    }


    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        for(auto i : adj[curr]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }


    if(visited[n]){
        cout<<-1<<endl;
    }
    else{
        cout<<-dp[n]<<endl;
    }

    return 0;
}