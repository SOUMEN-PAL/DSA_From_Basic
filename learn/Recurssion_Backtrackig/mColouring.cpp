#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool isSafe(vector<int> adj[] , vector<int> &color , int node , int col){
        for(auto i: adj[node]){
            if(color[i] == col){
                return false;
            }
        }
        return true;
    }
    
  
    bool helper(vector<int> adj[] , int m ,int node , int v , vector<int> &color){
        if(node == v){
            return true;
        }
        
        for(int i = 0 ; i<m ; i++){
            if(isSafe(adj , color , node , i)){
                color[node] = i;
                if(helper(adj , m , node + 1 , v , color)) return true;
                color[node] = -1;
            }
        }
        return false;
    }
    
  
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<int> color(v , -1);
        
        vector<int> adj[v];
        for(auto i : edges){
            int u = i.first;
            int v = i.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return helper(adj , m , 0 , v , color);
    }
};


int main() {


    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
            2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = { l1, l2 }; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
            << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}