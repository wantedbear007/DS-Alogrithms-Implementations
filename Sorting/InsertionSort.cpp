#include<iostream>
using namespace std;

void insertionSort(int arr[], int size) {

    for (int i = 1; i < size; i++) {
        int k = i;
        while (k > 0 && arr[k - 1] > arr[k]) {
            int temp = arr[k - 1];
            arr[k - 1] = arr[k];
            arr[k] = temp;

            k--;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
}


int main() {
    cout << "Program is working :)" << endl;
    int arr[] = { 5, 1, 4, 2, 8 };
    insertionSort(arr, 5);


    return 0;
}