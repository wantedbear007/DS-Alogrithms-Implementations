#include<iostream>
using namespace std;

struct node {
    int data;
    node * next = NULL;
};

node * start = NULL;

void insert(int value) {
    node * dataNode = new node();
    dataNode -> data = value;
    dataNode -> next = start;

    if (start == NULL) {
        start = dataNode;
    } else {
        node * temp = start;
        if (temp -> next == NULL) {
            temp -> next = dataNode;
        } else {

        while (temp -> next != start) {
        cout << "inside else "<< endl;
            temp = temp -> next;
        }
        temp -> next = dataNode;
        }
    }
}

void traverse() {
    node * temp = start;
    do {
        cout << temp -> data << ", ";
        temp = temp -> next;
    } while (temp != start);

}

int main() {
    cout << "Program is working fine" << endl;
    insert(34);
    insert(43);
    insert(24);
    insert(24);

    cout << "Insertion done" << endl;
    traverse();
    return 0;
}