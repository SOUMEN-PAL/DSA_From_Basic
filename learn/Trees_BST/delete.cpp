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

// In order sucessor
Node * nextGreater(Node *root){
    Node * curr = root;
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}


Node *deleteNode(Node* root , int data){
    if(root == NULL){
        return NULL;
    }

    if(root->data > data){
        root->left = deleteNode(root->left , data);
    }    
    else if(root->data < data){
        root->right = deleteNode(root->right , data);
    }
    else{
        // rot->data is equal to data;
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = nextGreater(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right , root->data); // deleting the sucessor replace node;
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

    root = deleteNode(root , 10);

    inorder(root);

    return 0;
}