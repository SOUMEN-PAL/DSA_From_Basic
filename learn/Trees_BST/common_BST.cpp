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

vector <int> findCommon(Node* root1, Node* root2)
{
    //Your code here
    stack<Node*> s1, s2;
    vector<int> arr;

    while (true) {
        if (root1 != NULL) {
            s1.push(root1);
            root1 = root1->left;
        }
        else if (root2 != NULL) {
            s2.push(root2);
            root2 = root2->left;
        }
        else if ((!s1.empty()) && (!s2.empty())) {
            root1 = s1.top();
            root2 = s2.top();
            if (root1->data == root2->data) {

                arr.push_back(root1->data);

                s1.pop();
                s2.pop();

                root1 = root1->right;
                root2 = root2->right;
            }
            else if (root1->data < root2->data) {
                s1.pop();
                root1 = root1->right;
                root2 = NULL;
            }
            else if (root1->data > root2->data) {
                s2.pop();
                root2 = root2->right;
                root1 = NULL;
            }
        }
        else {
            break;
        }
    }

    return arr;
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

    Node* root2 = new Node(10);
    Node* l5 = new Node(5);
    Node* r5 = new Node(15);
    Node* l6 = new Node(3);
    Node* r6 = new Node(7);
    Node* l7 = new Node(11);
    Node* r7 = new Node(18);
    Node* l8 = new Node(1);

    root2->left = l5;
    root2->right = r5;
    l5->left = l6;
    l5->right = r6;
    r5->left = l7;
    r5->right = r7;
    l6->left = l8;


    vector<int> arr = findCommon(root, root2);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    



    return 0;
}