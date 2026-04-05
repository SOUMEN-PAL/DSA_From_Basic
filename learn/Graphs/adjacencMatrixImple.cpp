#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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