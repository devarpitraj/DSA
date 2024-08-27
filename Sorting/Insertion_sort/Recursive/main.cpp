#include<iostream>
#include<vector>
#include<algorithm>

void insertion_sort(std::vector<int>& vec, int i) {
    if(i > vec.size()) return;

    int temp = vec[i];
    int j = i - 1;
    for( ; j  >= 0; j--) {
        if(temp < vec[j]) {
            vec[j + 1] = vec[j];
        } else break;
    }
    vec[j + 1] = temp;

    return insertion_sort(vec, i + 1);
}

int main() {
    std::vector<int> vec {-2, 7, -5, 8, 6, 10, 1, 0, 4};
    std::cout << "Before Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    insertion_sort(vec, 1);
    std::cout << "After Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;
}