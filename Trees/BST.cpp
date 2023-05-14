#include<iostream>
#include<queue>
using namespace std;

struct bstNode {
    int data = 0;
    bstNode * left = NULL, * right = NULL;

    bstNode(int data) {
        this -> data = data;
    }
};

bstNode * insert() {
    int value = 0;
    cout << "Enter the root value: "; cin >> value;

    if (value == -1) return NULL;

    bstNode * root = new bstNode(value);
    queue<bstNode*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0) {
        bstNode * front = pendingNodes.front();
        pendingNodes.pop();

        int leftData = 0, rightData = 0;
        cout << "Enter the left child data of " << front -> data << ": ";
        cin >> leftData;
        
        if (leftData != -1) {
            bstNode * leftNode = new bstNode(leftData);
            front -> left = leftNode;
            pendingNodes.push(leftNode);
        }

        cout << "Enter the right child data of " << front -> data << ": ";
        cin >> rightData;

        if (rightData != -1) {
            bstNode * rightNode = new bstNode(rightData);
            front -> right = rightNode;
            pendingNodes.push(rightNode);
        }
    }

    return root;
}

void traverse(bstNode * root) {
    if (root == NULL) return;
    cout << root -> data << ": ";
    if (root -> left != NULL) {
        cout << root -> left -> data << ", ";
    }

    if (root -> right != NULL) {
        cout << root -> right -> data << ", ";
    }
    cout << endl;
    traverse(root -> left);
    traverse(root -> right);
}

int main() {
    cout << "Program is working :)" << endl;

    bstNode * root = insert();
    traverse(root);

    return 0;
}