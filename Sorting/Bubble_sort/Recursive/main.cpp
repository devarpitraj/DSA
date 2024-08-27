#include<iostream>
#include<vector>
#include<algorithm>

void bubble_sort(std::vector<int>& vec, int size) {
    if(size == 0 || size == 1) return;

    for(int i = 0; i < size - 1; i++) {
        if(vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
    }

    return bubble_sort(vec, size - 1);
}

int main() {
    std::vector<int> vec{9, 12, 0, -1, 6, 13, 2, 3, 2};
    std::cout << "Before Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    bubble_sort(vec, vec.size());
    std::cout << "After Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}