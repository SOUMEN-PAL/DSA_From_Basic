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


bool createpath(Node *root , int p1 , vector<Node*> &res){
    if(root == NULL){
        return false;
    }
    if(root->data == p1){
        res.push_back(root);
        return true;
    }

    if(createpath(root->left , p1 , res) || createpath(root->right , p1 , res)){
        res.push_back(root);
        return true;
    }

    return false;
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


    vector<Node*> res;
    createpath(root , 50 , res);

    for(auto i : res){
        cout<<i->data<<" ";
    }



    return 0;
}