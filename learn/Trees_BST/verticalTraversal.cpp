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

void vTraversal(Node *root){
    map<int , vector<int>> mp;
    queue<pair<Node * , int>> q;
    q.push({root , 0});
    while(q.empty() == false){
        Node *curr = q.front().first;
        int hd = q.front().second;
        mp[hd].push_back(curr->data);
        q.pop();

        if(curr->left != NULL){
            q.push({curr->left , hd-1});
        }
        if(curr->right != NULL){
            q.push({curr->right , hd+1});
        }
    }

    for(auto i : mp){
        cout<<i.first<<": ";
        for(auto j : i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }

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

    vTraversal(root);

    return 0;
}