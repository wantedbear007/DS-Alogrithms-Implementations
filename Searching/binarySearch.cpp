#include<iostream>
using namespace std;



int binarySearch(int arr[], int value, int right, int left = 0) {
    if (right >= left) {
        int mid = (right + left) / 2;

        if (arr[mid] == value) return mid;
        if (value > arr[mid]) {return binarySearch(arr, value, right, mid + 1);} 
        else {return binarySearch(arr, value, mid - 1, left);}
    }

    return -1;
}

int main() {
    cout << "Program is working :)" << endl;
    cout << "-1 means not available in the array otherwise it will return index" << endl;
    int arr[] = {10, 20, 67, 88, 92, 100};
    cout << binarySearch(arr, 67, 5) << endl;
    cout  << binarySearch(arr, 102, 5) << endl;
    cout  << binarySearch(arr, 92, 5) << endl;


    return 0;
}