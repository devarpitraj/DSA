#include<iostream>
#include<vector>

bool isSorted(int arr[], int size) {
    if(size == 0 || size == 1) return true;

    if(arr[0] > arr[1]) return false;
    else {
        return isSorted(arr + 1, size - 1);
    }
}

int main() {
    int arr[5] {1, 2, 3, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    bool ans = isSorted(arr, size);

    if(ans) std::cout << "Array is Sorted" << std::endl;
    else std::cout << "Array is not Sorted" << std::endl;

    return 0;
}