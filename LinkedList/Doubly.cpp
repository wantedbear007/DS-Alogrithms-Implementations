#include<iostream>
using namespace std;

struct node {
    int data;
    node * prev = NULL;
    node * next = NULL;
};

node * start = NULL;

void insert(int value) {
    node * dataNode = new node();

    dataNode -> data = value;

    if (start == NULL) {
        start = dataNode;
    } else {
        if (start -> next == NULL) {
            dataNode -> prev = start;
            start -> next = dataNode;
        } else {
            node * temp = start;
            while (temp -> next != NULL) {
                temp = temp -> next;
            }
            dataNode -> prev = temp;
            temp -> next = dataNode;
        }
    }
}

void traverse() {

    if (start == NULL) {
        cout << "list is empty";
    } 
    node * temp = start;
    while (temp != NULL) {
        cout << temp -> data << ", ";
        temp = temp -> next;
    }
}

void reverse_print() {
    node * temp = start;

    while (temp -> next != NULL) {
        temp = temp -> next;
    }

    while (temp != NULL) {
        cout << temp -> data << ", ";
        temp = temp -> prev;
    }
}

int main() {
    cout << "Program is working fine :)" << endl;
    insert(12);
    insert(11);
    insert(14);
    insert(16);


    traverse();
    cout << "\nPrinting in reverse order " << endl;
    reverse_print();
    return 0;
}