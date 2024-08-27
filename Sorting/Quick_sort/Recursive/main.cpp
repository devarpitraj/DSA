#include<iostream>
#include<vector>
#include<algorithm>

int partition(std::vector<int>& vec, int s, int e) {
    // pivot element
    int pivot = vec[s];

    // count elements that are <= pivot
    int cnt = std::count_if(vec.begin() + s + 1, vec.begin() + e + 1, [pivot](int i) { return i <= pivot;});
    // int cnt{};
    // for(int i = s + 1; i <= e; i++) {
    //     if(vec[i] <= pivot) cnt++;
    // }


    // place pivot at correct position
    int pivotIndex = s + cnt;
    std::swap(vec[pivotIndex], vec[s]);

    // left and right part of pivot
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex) {

        // goto element which is > pivot
        // move i ahead if <= pivot
        while(vec[i] <= pivot) i++;

        //goto element which is <= pivot
        // move back j if > pivot
        while(vec[j] > pivot) j--;

        // swap the vec[i] and vec[j] if i < pivotIndex && j > pivotIndex
        if(i < pivotIndex && j > pivotIndex) {
            std::swap(vec[i], vec[j]);
            i++;
            j--;
        }
            
    }

    return pivotIndex;
}

void quick_sort(std::vector<int>& vec, int s, int e) {
    // base case
    if(s >= e) return;

    // partition
    int p = partition(vec, s, e);

    // left part sorting
    quick_sort(vec, s, p - 1);

    // right part sorting
    quick_sort(vec, p + 1, e);

}

int main() {
    std::vector<int> vec{9, 2, 0, -1, -4, 7, 10, -1};
    std::cout << "Before Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    quick_sort(vec, 0, vec.size() - 1);
    std::cout << "After Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}