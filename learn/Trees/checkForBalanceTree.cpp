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


int height(Node *root){
    if(root == NULL)
    {
        return 0;
    }
    return max(height(root->left) , height(root->right))+1;
}

// Naive solution //
bool isBalanced(Node *root){
    if(root==NULL){
        return true;
    }
    int lth = height(root->left);
    int rth = height(root->right);

    return (abs(lth-rth)<=1 && isBalanced(root->left) && isBalanced(root->right));
}

// Efficient solution //
int IsBalanced(Node *root){
    if(root == NULL)
    {
        return 0;
    }
    int lh = IsBalanced(root->left);
    if(lh == -1){
        return -1;
    }
    int rh = IsBalanced(root->right);
    if(rh == -1){
        return -1;
    }
    if(abs(lh - rh) > 1){
        return -1;
    }

    return max(lh , rh) + 1;
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

    cout<<isBalanced(root)<<endl;

    int res = IsBalanced(root);
    if(res == -1){
        cout<<"Not Balanced"<<endl;
    }
    else{
        cout<<"Is balanced"<<endl;
    }
    return 0;
}