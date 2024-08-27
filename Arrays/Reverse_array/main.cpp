#include<iostream>

// void swapAlt(int arr[], int size) {
//     // int size = sizeof(arr) / sizeof(arr[0]);

//     for(auto i = 0; i < size - 1; i += 2) {
//         int temp = arr[i];
//         arr[i] = arr[i + 1];
//         arr[i + 1] = temp;
//     }
// }

int main() {
    int arr[5] {1, 2, 3, 4, 5};

    int size = sizeof(arr) / sizeof(arr[0]);
    int start{0};
    int last{size - 1};

    // swapAlt(arr, size);

    while(start < last) {
        int temp = arr[start];
        arr[start] = arr[last];
        arr[last] = temp;

        start++;
        last--;
    }

    for(auto i: arr) std::cout << i << std::endl;

    return 0;
}