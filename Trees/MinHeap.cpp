#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at 'rootIndex'
void heapify(int arr[], int size, int rootIndex) {
    int smallest = rootIndex;  // Initialize smallest as root
    int leftChild = 2 * rootIndex + 1;  // Left child index
    int rightChild = 2 * rootIndex + 2; // Right child index

    // If left child is smaller than root
    if (leftChild < size && arr[leftChild] < arr[smallest])
        smallest = leftChild;

    // If right child is smaller than smallest so far
    if (rightChild < size && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    // If smallest is not root
    if (smallest != rootIndex) {
        swap(arr[rootIndex], arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, size, smallest);
    }
}

// Function to perform heap sort on an array
void heapSort(int arr[], int size) {
    // Build a min heap (rearrange the array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // Extract elements from the heap one by one
    for (int i = size - 1; i > 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call min heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[10] = {4, 10, 3, 5, 1, 8, 7, 2, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, size);

    cout << "Sorted array (using heap sort): ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
