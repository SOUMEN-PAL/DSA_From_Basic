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
void inorder(Node* root, vector<int>& arr) {
    if (root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}



// Naive approach O(n) + n AS : O(n+h)
bool isPair(vector<int> arr, int target) {
    int l = 0, h = arr.size() - 1;
    while (l < h) {
        int sum = arr[l] + arr[h];
        if (sum == target) {
            return true;
        }
        else if (sum > target) {
            h = h - 1;
        }
        else {
            l = l + 1;
        }
    }
    return false;
}

bool isPair(Node* root, int target) {
    vector<int> arr;
    inorder(root, arr);
    return isPair(arr, target);
}


//Method 2 hashing tc o(n) as : o(n)

bool is_pair(Node* root, int target, unordered_set<int>& hs) {
    if (root == NULL) {
        return false;
    }

    if (is_pair(root->left, target, hs) == true) {
        return true;
    }
    if (hs.find(target - root->data) != hs.end()) {
        return true;
    }
    hs.insert(root->data);
    return is_pair(root->right, target, hs);

}

//Moremefficient o(n) TC , o(h) as

bool isPairSum(Node* root, int target) {
    if (root == NULL) {
        return false;
    }

    stack<Node*> l, r;
    Node* root1 = root, * root2 = root;

    while (root1) {
        l.push(root1);
        root1 = root1->left;
    }

    while (root2) {
        r.push(root2);
        root2 = root2->right;
    }

    while (l.empty() == false && r.empty() == false && l.top() != r.top()) {
        Node* lnode = l.top();
        Node* rnode = r.top();

        int leftval = lnode->data;
        int rightval = rnode->data;

        int sum = leftval + rightval;
        if (sum == target) {
            return true;
        }
        else if (sum < target) {
            l.pop();
            lnode = lnode->right;
            while (lnode) {
                l.push(lnode);
                lnode = lnode->left;
            }
        }
        else {
            r.pop();
            rnode = rnode->left;
            while (rnode)
            {
                rnode = rnode->right;
            }

        }
    }

    return false;
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

    cout << isPairSum(root, 20);

    return 0;
}