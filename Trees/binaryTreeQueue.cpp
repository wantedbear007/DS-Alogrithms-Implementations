#include<iostream>
#include<queue>
using namespace std;

struct binaryTree {
    int data;
    binaryTree * left, * right;

    binaryTree(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

binaryTree * insert() {
    int value = 0;
    cout << "Enter the root data: "; cin >> value;

    if (value == -1) return NULL;

    binaryTree * root = new binaryTree(value);
    queue<binaryTree*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0) {
        binaryTree * front = pendingNodes.front();
        pendingNodes.pop();

        int left = 0, right = 0;
        cout << "Enter the left child data for " << front -> data << ": ";
        cin >> left;

        if (left != -1) {
            binaryTree * leftNode = new binaryTree(left);
            front -> left = leftNode;
            pendingNodes.push(leftNode);
        }

        cout << "Enter the right child data for " << front -> data << ": ";
        cin >> right;

        if (right != -1) {
            binaryTree * rightNode = new binaryTree(right);
            front -> right = rightNode;
            pendingNodes.push(rightNode);
        }
    }     

    return root;
}

void traverse(binaryTree * root) {
    if (root == NULL) return;
    cout << root -> data << ": ";

    
    if (root -> left != NULL) {
        cout << "L" << root -> left -> data << ", ";
    }

    if (root -> right != NULL) {
        cout << "R" <<root -> right -> data << ", ";
    }

    cout << endl;

    traverse(root -> left);
    traverse(root -> right);
}

// in-order traversal
void inOrder(binaryTree * root) {
    if (root == NULL) return;

    inOrder(root -> left);
    cout << root -> data << ", ";
    inOrder(root -> right);
}

int main() {
    cout << "Program is working :)" << endl;
    binaryTree * root = insert();

    traverse(root);

    return 0;
}