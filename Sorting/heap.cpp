#include <iostream>
#include <vector>

// Helper function to swap two elements in an array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Helper function to maintain the max heap property
void heapify(std::vector<int>& arr, int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest);
    }
}

// Heap Sort function
void heapSort(std::vector<int>& arr) {
    int size = arr.size();

    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // Extract elements from the heap one by one
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move current root to the end
        heapify(arr, i, 0);    // Heapify the reduced heap
    }
}

int main() {
    std::vector<int> arr = {9, 4, 7, 1, 2, 6, 3, 8, 5};

    std::cout << "Original array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    heapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
