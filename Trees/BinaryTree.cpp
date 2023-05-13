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

// destructor to delete tree
    ~binaryTree() {
        delete left, right;
        // delete right;
    }
};

// move this
binaryTree * insertOptimized() {
    int rootVal = 0; 
    cout << "Enter the root value: "; cin >> rootVal;

    binaryTree * root = new binaryTree(rootVal);
    queue<binaryTree*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0) {
        binaryTree * frontNode = pendingNodes.front();
        pendingNodes.pop();

        int leftData = 0, rightData = 0;
        cout << "Enter the left child data; "; cin >> leftData;
        if (leftData != -1) {
            binaryTree * leftNode = new binaryTree(leftData);
            frontNode->left = leftNode;
            pendingNodes.push(leftNode);
        }

        cout << "Enter the right child data: "; cin >> rightData;
        if (rightData != -1) {
            binaryTree * rightNode = new binaryTree(rightData);
            frontNode -> right = rightNode;
            pendingNodes.push(rightNode);
        }
     }

     return root;

}

// easy way
void printTree(binaryTree * root) {  
    if (root == NULL) return;

    cout << root -> data << ", ";
    printTree(root -> left);
    printTree(root -> right);
}

// difficult way
void printDetailedTree(binaryTree * root) {
    if (root == NULL) return;
    cout << root -> data << ": ";
    if (root -> left != NULL) cout << "left " << root -> left -> data;
    if (root -> right != NULL) cout << "right " << root -> right -> data;

    cout << endl;
    printDetailedTree(root -> left);
    printDetailedTree(root -> right);
}

// insert data
// DISCLAIMER: Use -1 to let program know that you don't want to enter any value
binaryTree * insertElement() {
    int value = 0;
    cout << "Enter the data: ";
    cin  >> value;

    if (value == -1) return NULL;

    binaryTree * root = new binaryTree(value);

    binaryTree * leftChild = insertElement();
    binaryTree * rightChild = insertElement();

    root -> left = leftChild;
    root -> right = rightChild;

    return root;
}

int main() {
    cout << "Program is working fine " << endl;
    // binaryTree * root = new binaryTree(1);
    // binaryTree * child0 = new binaryTree(2);
    // binaryTree * child1 = new binaryTree(3);
    // root -> left = child0;
    // root -> right = child1;

    // printTree(root);     

    binaryTree * root = insertElement();

    printDetailedTree(root);
    delete root;


    return 0;
}