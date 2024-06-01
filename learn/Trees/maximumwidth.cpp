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

int MaximumWIdth(Node *root){
    if(root == NULL){
        return 0;
    }

    int width = INT_MIN;
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        int count = q.size();
        for(int i = 0 ; i<count ; i++){
            Node *curr = q.front();
            q.pop();
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        width = max(width , count);
    }
    return width;
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

    cout<<MaximumWIdth(root)<<endl;

    return 0;
}