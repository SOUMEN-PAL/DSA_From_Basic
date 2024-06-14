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



Node* createTree(int arr[], int n)
{
    unordered_map<int, Node*> hm;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            root = new Node(i);
            hm.insert({ i , root });
        }
        else {
            hm[i] = new Node(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            continue;
        }

        if (hm[arr[i]]->left == NULL) {
            hm[arr[i]]->left = hm[i];
        }
        else {
            hm[arr[i]]->right = hm[i];
        }
    }
    return root;
}



void levelOrderLineByLine(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int count = q.size();
        for (int i = 0; i < count; i++) {
            Node* curr = q.front();
            cout << curr->data << " ";
            q.pop();
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}



int main() {
    int arr[] = { -1, 0 , 0 , 1,1,3,5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = createTree(arr, n);

    levelOrderLineByLine(root);


    return 0;
}