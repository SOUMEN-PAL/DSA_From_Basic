#include <bits/stdc++.h>
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

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


Node *insertNode(Node *root , int d){
    if(root == NULL){
        return new Node(d);
    }
    else if(root->data < d){
        root->right = insertNode(root->right , d);
    } 
    else if(root->data > d){
        root->left = insertNode(root->left , d);
    }
    return root;
}


int main() {
    // Create a Binary search tree
    Node* root = new Node(10);
    Node* l1 = new Node(5);
    Node* r1 = new Node(15);
    Node* l2 = new Node(3);
    Node* r2 = new Node(7);
    Node* l3 = new Node(12);
    Node* r3 = new Node(18);
    Node* l4 = new Node(1);

    root->left = l1;
    root->right = r1;
    l1->left = l2;
    l1->right = r2;
    r1->left = l3;
    r1->right = r3;
    l2->left = l4;

    inorder(root);
    cout<<endl;
    root = insertNode(root , 20);
    inorder(root);
    cout<<endl;

    return 0;
}