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


int helper(Node *root){
    if(root == NULL){
        return true;
    }

    if(root->left == NULL && root->right == NULL){
        return root->data;
    }

    int sum = 0;
    sum += helper(root->left);
    sum += helper(root->right);

    if(sum == root->data){
        return root->data;
    }
    else{
        return INT_MIN;
    }

    
}

bool childrenSumProperty(Node *root)
{
    int res = helper(root);
    return res == root->data;
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

    cout<<childrenSumProperty(root);

    return 0;
}