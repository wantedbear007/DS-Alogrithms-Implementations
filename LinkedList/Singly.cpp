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

    if (start == NULL) {
        start = dataNode;
    } else {
        node * temp = start;
        temp = start;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = dataNode;
    }
}

void iterate() {
    node * temp = start;

    while (temp != NULL) {
        cout << temp -> data << ", ";
        temp = temp -> next;
    }
}

int main() {
    cout << "Program is working" << endl;
    insert(12);
    insert(13);
    insert(12);
    insert(16);
    insert(18);

    iterate();
    return 0;
}