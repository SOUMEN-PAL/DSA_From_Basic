#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adjMatrix , int v , int u , int val){
    adjMatrix[v][u] = val;
    adjMatrix[u][v] = val;
}


void printMatrix(vector<vector<int>> &adjMatrix){
    for(int i = 0 ; i < adjMatrix.size() ; i++){
        for(int j = 0 ; j < adjMatrix[i].size() ; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}



int primsMst(vector<vector<int>> &graph  , int v){
    vector<int> key(v, INT_MAX);   // Proper initialization of key array
    vector<bool> mstSet(v, false);
    int res = 0;

    key[0] = 0;

    for(int cnt = 0 ; cnt < v ; cnt++){
        int u = -1;
        for(int i = 0 ; i<v ; i++){
            if(!mstSet[i] && (u == -1 || key[i] < key[u])){
                u = i;
            }
        }

        mstSet[u] = true;
        res = res + key[u];

        for(int i = 0 ; i<v ; i++){
            if(graph[u][i] != 0 && mstSet[i] == false){
                key[i] = min(key[i] , graph[u][i]);
            }
        }
    }
    return res;
}



//another approach
int PrimsAlgorithm(vector<vector<int>> &graph , int v){
    vector<int> visited(v , false);
    vector<pair<int , pair<int , int>>> mst_graph;
    priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>>, greater<pair<int , pair<int , int>>>> pq;
    
    pq.push({0 , {0 , -1}});
    int sum = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second.first;
        int weight = it.first;
        int parent = it.second.second;

        if(visited[node]){
            continue;
        }

        visited[node] = true;
        sum += weight;
        mst_graph.push_back({weight , {node , parent}}); // storing the mst graph repesentation of the graph//



        for(int i = 0 ; i<v ; i++){
            if(graph[node][i] != 0 && visited[i] == false){
                pq.push({graph[node][i] , {i , node}});
            }
        }
    }
    return sum;
}


int main(){
    
    int v = 4;
    vector<vector<int>> adjMatrix(v , vector<int>(v , 0));
    addEdge(adjMatrix , 0 , 0 , 0);
    addEdge(adjMatrix , 0 , 1 , 5);
    addEdge(adjMatrix , 0 , 2 , 8);
    addEdge(adjMatrix , 0 , 3 , 0);
    addEdge(adjMatrix , 1 , 1 , 0);
    addEdge(adjMatrix , 1 , 2 , 10);
    addEdge(adjMatrix , 1 , 3 , 15);
    addEdge(adjMatrix , 2 , 2 , 0);
    addEdge(adjMatrix , 2 , 3 , 20);
    addEdge(adjMatrix , 3 , 3 , 0);

    
    printMatrix(adjMatrix);
    cout<<endl;
    cout<<primsMst(adjMatrix , v);
    cout<<endl;
    cout<<PrimsAlgorithm(adjMatrix , v)<<endl;
    
    return 0;
}