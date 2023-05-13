#include<iostream>
#include<queue>
using namespace std;

class treeNode {
    public:
        int data;
        vector<treeNode*> children;

    treeNode(int data) {
        this -> data = data;
    }   
};

treeNode * insertElement() {
    int value = 0, child = 0;
    cout << "Enter the root value: "; cin >> value;

    treeNode * root = new treeNode(value);

    queue<treeNode*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        treeNode * node = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the number of children: "; cin >> child;

        for (int i = 0; i < child; i++) {
            cout << "Enter the child of parent: " << node -> data << endl;
            int childData;
            cin >> childData;

            treeNode * childNode = new treeNode(childData); 
            node -> children.push_back(childNode);

            pendingNodes.push(childNode);
        }
    }

    return root;

}

// to print number of nodes
int numNodes(treeNode * root) {
    int count = 1;
    for (int i = 0; i < root->children.size(); i++) {
        count += number(root -> children[i]);
    }
    return count;
}

void printTree(treeNode * root) {
    cout << root -> data << ": ";
    
    for (int i = 0; i < root->children.size(); i++) {
        cout << root -> children[i] -> data << " -> ";
    }

    cout << endl;

    for (int i = 0; i < root->children.size(); i++) {
        cout << root -> children[i] << endl;
    }
}

// to delete a tree
void deleteTree(treeNode * root) {
    for (int i = 0; i < root -> children.size(); i++) {
        deleteTree(root -> children[i]);
    }

     delete root;
}


int main() {
    cout << "Program is working fine" << endl;
    treeNode * root = insertElement();

    printTree(root);

    return 0;
}



