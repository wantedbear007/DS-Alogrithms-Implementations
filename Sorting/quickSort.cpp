#include<iostream>
using namespace std;

int partition(int arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j <= low - 1) {
            j--;
        }

        if (i < j) {
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;

}

void quickSort(int arr[], int high, int low) {
    if (low < high) {
        int partition = part(arr, low, high);
        quickSort(arr, partition + 1, low);
        quickSort(arr, high, partition -  1);
    }

}

int main() {
    cout << "Program is working :)" << endl;
    int arr[] = {4, 2, 1, 5, 3};

    quickSort(arr, 5, 0);
    return 0;
}