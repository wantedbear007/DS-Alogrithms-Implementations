#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next = NULL;
        Node(int data) {
            this -> data = data;
        }
    };

    Node* frontPtr;
    Node* rearPtr;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return frontPtr == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontPtr = newNode;
            rearPtr = newNode;
        } else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty." << endl;
            return;
        }

        Node* temp = frontPtr;
        frontPtr = frontPtr->next;

        if (frontPtr == nullptr) {
            rearPtr = nullptr;
        }

        delete temp;
    }

    int front() const {
        if (isEmpty()) {
            cout << "Error: Queue is empty." << endl;
            return 0;
        }

        return frontPtr->data;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = frontPtr;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    using namespace std;

    Queue queue;

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);

    queue.display();  // Output: 5 10 15

    cout << "Front element: " << queue.front() << endl;  // Output: 5

    queue.dequeue();
    queue.display();  // Output: 10 15

    cout << "Front element: " << queue.front() << endl;  // Output: 10

    queue.dequeue();
    queue.display();  // Output: 15

    cout << "Front element: " << queue.front() << endl;  // Output: 15

    queue.dequeue();
    queue.display();  // Output: Queue is empty.

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;  // Output: Yes

    return 0;
}
