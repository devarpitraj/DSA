#include<iostream>

int BinarySearch(int arr[], int size, int key) {
    int start =  0;
    int end = size - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;    //better than mid = (start + end) / 2;
        if(key == arr[mid]) return mid;
        else if(key < arr[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main() {
    int arr[5] {2, 3,  5, 7, 8};

    int index = BinarySearch(arr, 5, 19);

    std::cout << "The index of 8 is : " << index << std::endl;

    return 0;
}