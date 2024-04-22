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


// Normal traversal and checking //
int max_in_tree(Node * root){
    if(root == NULL){
        return INT_MIN;
    }

    queue<Node *> q;
    int hs = INT_MIN;
    q.push(root);
    
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        hs = max(hs , curr->data);
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    return hs;
}

int main(){
    Node *root = new Node(10);
    Node *l1 = new Node(20);
    Node *r1 = new Node(30);
    Node *l2 = new Node(40);
    Node *r2 = new Node(50);
    Node *l3 = new Node(60);
    Node *r3 = new Node(70);
    Node *l4 = new Node(80);
    Node *r4 = new Node(90);

    root->left = l1;
    root->right = r1;
    l1->left = l2;
    l1->right = r2;
    r1->left = l3;
    r1->right = r3;
    l2->left = l4;
    l2->right = r4;

    cout<<max_in_tree(root)<<endl;

    return 0;
}