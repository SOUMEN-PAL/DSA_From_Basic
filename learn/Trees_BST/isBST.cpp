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

bool isBst(Node* root, int low, int high) {
    if (root == NULL) { return true; }
    return root->data > low && root->data < high && isBst(root->left, low, root->data) && isBst(root->right, root->data, high);
}


bool is_BST(Node* root, int& prev) {
    if (root == NULL) {
        return true;
    }

    if (is_BST(root->left, prev) == false) { return false; }

    if (root->data <= prev) {
        return false;
    }
    prev = root->data;
    return is_BST(root->right, prev);
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

    cout << isBst(root, INT_MIN, INT_MAX) << endl;

    int prev = INT_MIN;
    cout << is_BST(root, prev) << endl;

    return 0;
}