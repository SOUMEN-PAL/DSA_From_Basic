#include<bits/stdc++.h>
using namespace std;

// Define Tree structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};


string DFS(Node *root, unordered_map<string, int> &temp, vector<Node*> &ans) {
    if (root == NULL) return "#";
    string x;
    x += to_string(root->data) + " ";
    x += DFS(root->left, temp, ans);
    x += DFS(root->right, temp, ans);
    
    if (temp[x] == 1) { // Found a duplicate
        ans.push_back(root);
    }
    temp[x]++;
    return x;
}


int main(){
    Node *root = new Node(10);
    Node *l1 = new Node(20);
    Node *r1 = new Node(30);
    Node *l2 = new Node(40);
    Node *r2 = new Node(50);
    Node *l3 = new Node(60);

    root->left = l1;
    root->right = r1;
    l1->left = l2;
    l1->right = r2;
    r1->left = l3;



    return 0;
}