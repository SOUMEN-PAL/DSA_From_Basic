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


// Vertical sum of a binary tree
// Naive solution
void helper(Node *root , int i , map<int , int> &mp){
    if(root == NULL){
        return;
    }
    

    mp[i] += root->data;
    helper(root->left , i-1 , mp);
    helper(root->right , i+1 , mp);

}

vector<int> verticalSum(Node *root){
    map<int , int> mp;
    vector<int> res;
    helper(root , 0 , mp);
    for(auto i : mp){
        cout<<i.first<<" ";
        res.push_back(i.second);
    }
    cout<<endl;

    return res;
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


    vector<int> res = verticalSum(root);

    for(auto i : res){
        cout<<i<<" ";
    }


    return 0;
}