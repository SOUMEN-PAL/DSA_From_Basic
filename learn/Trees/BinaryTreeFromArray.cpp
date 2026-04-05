#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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