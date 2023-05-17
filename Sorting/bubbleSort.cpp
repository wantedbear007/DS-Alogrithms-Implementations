#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] >= arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }


    
}

int main() {
    cout << "Program is working :)" << endl;
    int arr[] = { 5, 1, 4, 2, 8 };

    cout << "Before sorting" << endl;
    for (int i = 0; i < sizeof(arr) / 4; i++) {
        cout << arr[i] << ", ";
    }

    cout << "\nAfter sorting " << endl;

    bubbleSort(arr, sizeof(arr) / 4);  

    return 0;
}