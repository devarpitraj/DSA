#include<iostream>
#include<vector>
#include<algorithm>

void selection_sort(std::vector<int>& vec, int i) {
    if(i == vec.size()) return;

    int minIndex = i;
    for(int j = i + 1; j < vec.size(); j++) {
        if(vec[j] < vec[minIndex]) minIndex = j;
    }
    std::swap(vec[minIndex], vec[i]);

    return selection_sort(vec, i + 1);
}

int main() {
    std::vector<int> vec{1, 9, 0, -2, 6, 3, -5, -5, 9};
    std::cout << "Before Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    selection_sort(vec, 0);
    std::cout << "After Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}