#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

//moris threaded tree code//

void morrisPreorder(Node * root) {
    Node *curr = root;
    
    while (curr) {
        if (!curr->left) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            Node* predecessor = curr->left;
            while (predecessor->right && predecessor->right != curr) {
                predecessor = predecessor->right;
            }

            if (!predecessor->right) {
                predecessor->right = curr;
               
                curr = curr->left;
            } else {
                predecessor->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main() {
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

    morrisPreorder(root);
    cout<<endl;
    return 0;
}
