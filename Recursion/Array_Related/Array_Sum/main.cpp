#include<iostream>

int add(int* arr, int size) {
    if(size == 0) return 0;

    int ans = 0;
    if(size == 1) return arr[0];
    else {
        ans = arr[0] + add(arr + 1, size - 1);
        return ans;
    }
}

int  main() {
    int arr[] {1, 2, 3, 4, 5, 10, -1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = add(arr, size);

    std::cout << "Sum of elements of array is: " << sum << std::endl;

    return 0;
}