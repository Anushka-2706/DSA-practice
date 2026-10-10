#include <iostream>
using namespace std;

int merge(int arr[], int low, int mid, int high) {
    int temp[10];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
    return 0;
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {12, 23, 56, 89, 45, 1, 30, 35, 53, 10};
    int size = sizeof(arr) / sizeof(int);
    int i;

    mergeSort(arr, 0, size - 1);

    for (i = 0; i < size; i++) {
       cout << arr[i] << " ";
    }

    cout << "NULL" << endl;

    return 0;
}