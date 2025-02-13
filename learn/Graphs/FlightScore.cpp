#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = numeric_limits<ll>::max();

struct State {
    ll cost;
    int city;
    int used; 
};

struct Compare {
    bool operator()(const State &a, const State &b) {
        return a.cost > b.cost;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
   
    vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
    dp[1][0] = 0;
    
    priority_queue<State, vector<State>, Compare> pq;
    pq.push({0, 1, 0});
    
    while (!pq.empty()){
        State cur = pq.top();
        pq.pop();
        
        int u = cur.city, used = cur.used;
        ll currCost = cur.cost;
        
        if (currCost != dp[u][used])
            continue;
        
        for (auto &edge : graph[u]){
            int v = edge.first;
            int c = edge.second;
            
            if (currCost + c < dp[v][used]){
                dp[v][used] = currCost + c;
                pq.push({dp[v][used], v, used});
            }
            
            if (used == 0) {
                ll newCost = currCost + (c / 2); 
                if (newCost < dp[v][1]){
                    dp[v][1] = newCost;
                    pq.push({dp[v][1], v, 1});
                }
            }
        }
    }
    
    ll answer = min(dp[n][0], dp[n][1]);
    cout << answer << "\n";
    
    return 0;
}
