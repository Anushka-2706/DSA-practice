#include <iostream>
using namespace std;

int binarysearch (int arr[], int size, int key) {
    int left, right, mid;
    left = 0, right = size-1;

    while (left <= right){
        mid = left + (right - left)/2;

        if (key > arr[mid]) {
            left = mid + 1; //right
        } else if (key < arr[mid]) {
            right = mid - 1; //left
        } else {
            return mid; //Found at 'mid' location
        }
    }
    return -1; //Not found

}
int main() {
    
    int arr[] = {22, 24, 30, 35, 40, 45};
    int key = 40;
    int size = 6; 
    int idx = binarysearch (arr, size, key);
    cout<<"Value is at:"<< idx; 
    return 0;
}