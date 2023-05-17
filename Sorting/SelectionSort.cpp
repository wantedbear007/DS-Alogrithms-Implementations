#include<iostream>
using namespace std;

int * selectionSort(int size, int arr[]) {
    
    for (int i = 0; i < size - 1; i++ ){
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] >= arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }


    return arr;

    
}

int main() {
    cout << "Program is working :)" << endl;
    
    int arr[] = { 5, 1, 4, 2, 8 };

    for (int i : arr) {
        cout << i << ", ";
    }

    int * ptr = selectionSort(5, arr);

    cout << "\nSorted " << endl;
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << ", ";
    }

    return 0;

}