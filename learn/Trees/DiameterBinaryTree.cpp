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

int res = 0;
// Function to return the diameter of a Binary Tree.
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    
    int lh = diameter(root->left) + 1;
    int rh = diameter(root->right) + 1;
    res = max(res , (lh + rh - 1));
    return max(lh , rh);
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


    int height = diameter(root);
    cout<<"Diameter of the tree is: "<<res<<endl;

    return 0;
}