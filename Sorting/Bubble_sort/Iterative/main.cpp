#include<iostream>
#include<vector>

void bubble_sort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) break;
    }
}

int main() {
    std::vector<int> arr {10, 8, 1, 1, 9, 6};

    std::cout << "Before Sorting : ";
    for(int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    bubble_sort(arr);

    std::cout << "After Sorting : ";
    for(int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}