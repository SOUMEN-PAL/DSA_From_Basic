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



//Naive solution //

bool createpath(Node *root , int p1 , vector<Node*> &res){
    if(root == NULL){
        return false;
    }
    res.push_back(root);
    if(root->data == p1){
        return true;
    }
    if(createpath(root->left , p1 , res) || createpath(root->right , p1 , res)){
        return true;
    }
    res.pop_back();
    return false;
}

Node* lca (Node *root , int n1 , int n2){
    vector<Node*> p1 , p2;
    if(!createpath(root , n1 , p1) || !createpath(root , n2 , p2)){
        return NULL;
    }

    // for(auto i : p1){
    //     cout<<i->data<<" ";
    // }
    // cout<<endl;

    // for(auto i : p2){
    //     cout<<i->data<<" ";
    // }
    // cout<<endl;

    for(int i = 0 ; i<p1.size()-1 && i<p2.size()-1 ; i++){
        if(p1[i+1]->data != p2[i+1]->data){
            return p1[i];
        }
    }
    return NULL;
}


//Efficient solution




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


    // vector<Node*> res;
    // createpath(root , 40 , res);

    // for(auto i : res){
    //     cout<<i->data<<" ";
    // }

    Node* r = lca(root , 60 , 40);
    cout<<r->data<<endl;


    return 0;
}