#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adjMatrix , int v , int u){
    adjMatrix[v][u] = 1;
    adjMatrix[u][v] = 1;
}


void printMatrix(vector<vector<int>> &adjMatrix){
    for(int i = 0 ; i < adjMatrix.size() ; i++){
        for(int j = 0 ; j < adjMatrix[i].size() ; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    
    int v = 4;
    vector<vector<int>> adjMatrix(v , vector<int>(v , 0));
    addEdge(adjMatrix , 0 , 1);
    addEdge(adjMatrix , 0 , 2);
    addEdge(adjMatrix , 1 , 2);
    addEdge(adjMatrix , 1 , 3);
    
    printMatrix(adjMatrix);
    
    return 0;
}