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


int minCameraCover(Node* root) {
    int cameras = 0;
    // Call the helper function to traverse the tree and install cameras
    installCameras(root, cameras);
    // If the root node is not covered, install a camera
    if (root->data == 0) {
        cameras++;
    }
    return cameras;
}

void installCameras(Node* node, int& cameras) {
    // Base case: If the node is null, return
    if (node == NULL) {
        return;
    }
    // Recursively install cameras on the left and right subtrees
    installCameras(node->left, cameras);
    installCameras(node->right, cameras);
    // If the node is not covered, install a camera
    if (node->data == 0) {
        // Mark the node and its parent as covered
        if (node->left != NULL) {
            node->left->data = 1;
        }
        if (node->right != NULL) {
            node->right->data = 1;
        }
        node->data = 1;
        cameras++;
    }
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