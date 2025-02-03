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


// Tree Traversals //
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}


vector<int> PreOrder(Node* root) {

    if (root != NULL) {
        vector<int> res;
        res.push_back(root->data);
        vector<int> left = PreOrder(root->left);
        vector<int> right = PreOrder(root->right);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());

        return res;
    }
    return {};
}


vector<int> PostOrder(Node* root) {

    if (root != NULL) {
        vector<int> res;

        vector<int> left = PostOrder(root->left);
        vector<int> right = PostOrder(root->right);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        res.push_back(root->data);
        return res;
    }
    return {};
}



vector<int> InOrder(Node* root) {

    if (root != NULL) {
        vector<int> res;

        vector<int> left = InOrder(root->left);

        vector<int> right = InOrder(root->right);
        res.insert(res.end(), left.begin(), left.end());
        res.push_back(root->data);
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
    return {};
}


//INorder treative
vector<int> InOrderIterative(Node* root) {
    vector<int> res;
    stack<Node*> s;
    Node* curr = root;
    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        res.push_back(curr->data);
        curr = curr->right;
    }
    return res;
}

//Preorder treative
vector<int> PreOrderIterative(Node* root) {
    vector<int> res;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        res.push_back(curr->data);
        if (curr->right != NULL) {
            s.push(curr->right);
        }
        if (curr->left != NULL) {
            s.push(curr->left);
        }
    }
    return res;
}

//Postorder treative
vector<int> PostOrderIterative(Node* root) {
    vector<int> res;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        res.push_back(curr->data);
        if (curr->left != NULL) {
            s.push(curr->left);
        }
        if (curr->right != NULL) {
            s.push(curr->right);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

//itreative preorder
vector<int> itret_pre(Node* root) {
    stack<Node*> s;
    vector<int> res;
    s.push(root);
    while (!s.empty() || root) {
        if (root) {
            res.push_back(root->data);
            s.push(root);
            root = root->left;
        }
        else {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    return res;
}

//itreative postOrder
vector<int> itreat_post(Node* root) {
    stack<Node*>s;
    vector<int> res;
    while (!s.empty() || root) {
        if (root) {
            res.push_back(root->data);
            s.push(root);
            root = root->right;
        }        
else {
            root = s.top();
            s.pop();
            root = root->left;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

//itreative one stack with out reversal
vector<int> itreat_post_noRev(Node* root) {
    stack<Node*> s;
    vector<int> res;

    while (!s.empty() || root) {
        if (root) {
            s.push(root);
            root = root->left;
        }
        else {
            root = s.top();
            if (root->right) {
                root = root->right;
            }
            else {
                res.push_back(root->data);
                s.pop();
                while (!s.empty() && s.top()->right == root) {
                    root = s.top();
                    s.pop();
                    res.push_back(root->data);
                }
                root = NULL;
            }
        }
    }
    return res;
}




int main() {

    Node* root = new Node(10);
    Node* l1 = new Node(20);
    Node* r1 = new Node(30);
    Node* l2 = new Node(40);
    Node* r2 = new Node(50);
    Node* l3 = new Node(60);

    root->left = l1;
    root->right = r1;
    l1->left = l2;
    l1->right = r2;
    r1->left = l3;

    cout << "InOrder Traversal: ";
    inOrder(root);
    cout << endl;
    cout << "preOrder Traversal: ";
    preOrder(root);
    cout << endl;
    cout << "postOrder Traversal: ";
    postOrder(root);
    cout << endl << endl;

    vector<int> res = PreOrder(root);

    cout << "Preorder: ";
    for (auto i : res) {
        cout << i << " ";
    }

    cout << endl;
    vector<int> post = PostOrder(root);
    cout << "Postorder: ";
    for (auto i : post) {
        cout << i << " ";
    }

    cout << endl;
    cout << "Inorder: ";
    vector<int> in = InOrder(root);
    for (auto i : in) {
        cout << i << " ";
    }

    cout << endl;
    cout << "Inorder Iterative: ";
    vector<int> inI = InOrderIterative(root);
    for (auto i : inI) {
        cout << i << " ";
    }

    cout << endl;
    cout << "Preorder Iterative: ";
    vector<int> preI = PreOrderIterative(root);
    for (auto i : preI) {
        cout << i << " ";
    }

    cout << endl;
    cout << "Postorder Iterative: ";
    vector<int> postI = PostOrderIterative(root);
    for (auto i : postI) {
        cout << i << " ";
    }



    return 0;
}