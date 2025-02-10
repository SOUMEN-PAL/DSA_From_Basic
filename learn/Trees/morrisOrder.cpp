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
                //preOrder Area
                // cout << curr->data << " ";
                curr = curr->left;
            } else {
                predecessor->right = NULL;
                //In Order area
                cout << curr->data << " ";
                curr = curr->right;
            }
            
        }
    }
}


void morrisPostorder(Node* root) {
    vector<int> postorder;  
    Node* curr = root;
    
    while (curr) {
        if (!curr->right) {
            postorder.push_back(curr->data);  
            curr = curr->left;  // Swap: Move Left instead of Right
        } else {
            Node* predecessor = curr->right;  // Swap: Find Rightmost of Right Subtree
            while (predecessor->left && predecessor->left != curr) {
                predecessor = predecessor->left;
            }

            if (!predecessor->left) {
                predecessor->left = curr;
                postorder.push_back(curr->data);  
                curr = curr->right;  // Swap: Move Right instead of Left
            } else {
                predecessor->left = NULL;
                curr = curr->left;  
            }
        }
    }

    // Reverse the collected preorder(Root → Right → Left) to get actual Postorder (Left → Right → Root)
    reverse(postorder.begin(), postorder.end());

    // Print postorder
    for (int val : postorder) {
        cout << val << " ";
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

    morrisPostorder(root);
    cout<<endl;
    return 0;
}
