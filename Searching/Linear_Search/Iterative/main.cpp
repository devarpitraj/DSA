#include<iostream>

bool LinearSearch(int arr[], int size, int key) {
    for(size_t i = 0; i < size; i++) {
        if(arr[i] == key) return 1;
    }
    return 0;
}

int main() {
    int array[10] { 1, 2, 3, 4, 5, 6};

    int size = sizeof(array) / sizeof(array[0]);

    bool found = LinearSearch(array, size, 10);

    if(found) std::cout << "Found" << std::endl;
    else std::cout << "Not Found" << std::endl;

    return 0;
}