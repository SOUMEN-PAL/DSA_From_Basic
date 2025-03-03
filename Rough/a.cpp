#include <bits/stdc++.h>
using namespace std;

class AVLNode {
    public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
    
    AVLNode(int key) {
        this->key = key;
        left = right = nullptr;
        height = 1;  // Initial height of a new node is 1
    }
};

class AVLTree {
    public:
    AVLNode* root;
    
    AVLTree() {
        root = nullptr;
    }
    
    // Get the height of the node
    int getHeight(AVLNode* node) {
        if (!node) return 0;
        return node->height;
    }
    
    // Update the height of the node
    void updateHeight(AVLNode* node) {
        if (node) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }
    
    // Get the balance factor of the node
    int getBalance(AVLNode* node) {
        if (!node) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    
    // Right rotate subtree rooted with z
    AVLNode* rightRotate(AVLNode* z) {
        AVLNode* y = z->left;
        AVLNode* T3 = y->right;
        
        // Perform rotation
        y->right = z;
        z->left = T3;
        
        // Update heights
        updateHeight(z);
        updateHeight(y);
        
        return y;
    }
    
    // Left rotate subtree rooted with z
    AVLNode* leftRotate(AVLNode* z) {
        AVLNode* y = z->right;
        AVLNode* T2 = y->left;
        
        // Perform rotation
        y->left = z;
        z->right = T2;
        
        // Update heights
        updateHeight(z);
        updateHeight(y);
        
        return y;
    }
    
    // Insert a node into the AVL tree
    AVLNode* insert(AVLNode* node, int key) {
        // Perform normal BST insertion
        if (!node) return new AVLNode(key);
        
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            return node;  // Duplicate keys are not allowed
        }
        
        // Update height of this ancestor node
        updateHeight(node);
        
        // Get the balance factor of this ancestor node
        int balance = getBalance(node);
        
        // If this node becomes unbalanced, then there are 4 cases
        
        // Left Left Case (LL)
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }
        
        // Right Right Case (RR)
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }
        
        // Left Right Case (LR)
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        // Right Left Case (RL)
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    // Helper function to find the node with the smallest value
    AVLNode* getMinValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    
    // Delete a node from the AVL tree
    AVLNode* deleteNode(AVLNode* root, int key) {
        // Perform standard BST delete
        if (!root) return root;
        
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node with only one child or no child
            if (!root->left || !root->right) {
                AVLNode* temp = root->left ? root->left : root->right;
                if (!temp) {
                    // No child case
                    temp = root;
                    root = nullptr;
                } else {
                    // One child case
                    *root = *temp;
                }
                delete temp;
            } else {
                // Node with two children: Get the inorder successor
                AVLNode* temp = getMinValueNode(root->right);
                
                // Copy the inorder successor's data to this node
                root->key = temp->key;
                
                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->key);
            }
        }
        
        // If the tree had only one node, then return
        if (!root) return root;
        
        // Update height of the current node
        updateHeight(root);
        
        // Get the balance factor of this node
        int balance = getBalance(root);
        
        // If this node becomes unbalanced, then there are 4 cases
        
        // Left Left Case (LL)
        if (balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }
        
        // Left Right Case (LR)
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        
        // Right Right Case (RR)
        if (balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }
        
        // Right Left Case (RL)
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
    }
    
    // Function to print the tree (for debugging purposes)
    void preOrder(AVLNode* node) {
        if (node) {
            cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
};

int main() {
    AVLTree avl;
    
    // Insert nodes into the AVL tree
    avl.root = avl.insert(avl.root, 10);
    avl.root = avl.insert(avl.root, 20);
    avl.root = avl.insert(avl.root, 30);
    avl.root = avl.insert(avl.root, 40);
    avl.root = avl.insert(avl.root, 50);
    avl.root = avl.insert(avl.root, 25);
    
    // Print the pre-order traversal of the AVL tree
    cout << "Pre-order traversal after insertions: ";
    avl.preOrder(avl.root);
    cout << endl;
    
    // Delete a node from the AVL tree
    avl.root = avl.deleteNode(avl.root, 20);
    
    // Print the pre-order traversal after deletion
    cout << "Pre-order traversal after deletion of 20: ";
    avl.preOrder(avl.root);
    cout << endl;
    
    return 0;
}