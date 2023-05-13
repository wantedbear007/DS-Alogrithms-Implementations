#include<iostream>
#include<vector>
using namespace std;

class treeNode {
    public:
        int data;
        vector<treeNode*> children;

    treeNode(int data) {
        this->data = data;
    }
};

// to create tree
treeNode * insert() {
    int data = 0, children = 0;
    cout << "Enter data: ";
    cin >> data;

    treeNode * node = new treeNode(data);
    cout << "Enter number of childrens: ";
    cin >> children;

    for (int i = 0; i < children; i++) {
        treeNode * child = insert();
        node -> children.push_back(child);
    }

    return node;
}

// to print trees
void printTree(treeNode * root) {

    if (root == NULL) return;

    cout << root -> data << ": ";

    for (int i = 0; i < root -> children.size(); i++) {
        cout << root -> children[i] -> data << "-> ";
    }

    cout << endl;

    for (int i = 0; i < root -> children.size(); i++){
        printTree(root -> children[i]);
    }
}

int main() {
    cout << "Program is working !" << endl;

    treeNode * root = insert();
    printTree(root);
    
    return 0;
}

