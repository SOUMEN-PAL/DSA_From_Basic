#include<bits/stdc++.h>
using namespace std;

// Define Node structure
class Node {
    public:
    int data;
    Node* next;
    
    // Constructor
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void addEdge(vector<int> arr[], int v, int u){
    arr[v].push_back(u);
    arr[u].push_back(v);
}

void addEdge(vector<Node*>& adjList, int v, int u){
    Node* newNode = new Node(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
    // The order does not matter in an undirected graph
    newNode = new Node(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void printList(vector<int> arr[], int v){
    for (int i = 0; i < v; i++) {
        cout << i << " -> ";
        for (auto x : arr[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}

void printList(vector<Node*> adjList, int v){
    for (int i = 0; i < v; i++) {
        cout << i << " -> ";
        Node* temp = adjList[i];
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(){
    int v = 4;
    vector<int> arr[v];
    addEdge(arr, 0, 1);
    addEdge(arr, 0, 2);
    addEdge(arr, 1, 2);
    addEdge(arr, 1, 3);
    
    cout << "Adjacency List Array Representation of Graph" << endl;
    printList(arr, v);
    
    vector<Node*> adjList(v, NULL);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    
    cout << "Adjacency List Linked List Representation of Graph" << endl;
    printList(adjList, v);
    
    return 0;
}