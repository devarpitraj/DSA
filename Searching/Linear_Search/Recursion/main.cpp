#include<iostream>

bool find(int* arr, int size, int key) {
    if(size == 0) return false;

    if(key == arr[0]) return true;
    else return find(arr + 1, size - 1, key);
}

int main() {
    int arr[] {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 7;

    bool found = find(arr, size, key);

    if(found) std::cout << key << " is present in the array" << std::endl;
    else std::cout << key << " is not present in the array" << std::endl;

    return 0;
}