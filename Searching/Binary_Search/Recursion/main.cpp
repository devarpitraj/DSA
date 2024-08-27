#include<iostream>

void print(int* arr, int size) {
    std::cout << "Array :";
    for(int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

bool binary_search(int* arr, int size, int key) {
    print(arr, size);
    if(size <= 0) return false;

    int mid = (size - 1) / 2;
    if(key == arr[mid]) return true;
    else if(key < arr[mid]) return binary_search(arr, mid, key);
    else return binary_search(arr + mid + 1, size - mid - 1, key);
}

bool binary_search_start_end(int* arr, int start, int end, int key) {
    if(start > end) return false;

    int mid = start + (end - start) / 2;

    if(key == arr[mid]) return true;
    else if(key < arr[mid]) end = mid - 1;
    else start = mid + 1;

    return binary_search_start_end(arr, start, end, key);
}

int main() {
    int arr[] {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 5;

    // bool found = binary_search(arr, size, key);

    int start = 0;
    int end = size - 1;
    bool found = binary_search_start_end(arr, start, end, key);

    if(found) std::cout << key << " is present in the array" << std::endl;
    else std::cout << key << " is not present in the array" << std::endl;

    return 0;
}

