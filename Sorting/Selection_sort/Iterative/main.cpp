#include<iostream>
#include<vector>

void selection_sort(std::vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        int minIndex = i;
        int idx;
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    std::vector<int> arr {6, 7, 3, 2, 9, 1};
    std::cout << "Given Array:";
    for(int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    selection_sort(arr);

    std::cout << "Sorted Array:";
    for(int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}