#include<iostream>
#include<vector>

void merge(std::vector<int>& vec, int s, int e) {
    int mid = s + (e - s) / 2;
    std::cout << "part to be sorted: ";
    for(int i = s; i <= e; i++) {
        std::cout << vec[i] << " ";
    } std::cout << std::endl;

    // break in 2 arrays
    // create new arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    std::vector<int> left(len1);
    std::vector<int> right(len2);

    // copy values from mainArray
    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++) left[i] = vec[mainArrayIndex++];

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++) right[i] = vec[mainArrayIndex++];

    std::cout << "left : ";
    for(int i : left) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "right : ";
    for(int i : right) std::cout << i << " ";
    std::cout << std::endl;


    // merge two sorted arrays
    int idx1 = 0;
    int idx2 = 0;
    mainArrayIndex = s;

    while(idx1 < len1 && idx2 < len2) {
        if(left[idx1] < right[idx2]) vec[mainArrayIndex++] = left[idx1++];
        else {
            vec[mainArrayIndex++] = right[idx2++];
        }
    }

    while(idx1 < len1) vec[mainArrayIndex++] = left[idx1++];
    while(idx2 < len2) vec[mainArrayIndex++] = right[idx2++];

    std::cout << "Afetr sorting : ";
    for(int i = s; i <= e; i++) {
        std::cout << vec[i] << " ";
    } std::cout << std::endl;
}

void merge_sort(std::vector<int>& vec, int s, int e) {
    // base case
    // single element left
    if(s >= e) return;

    int mid = s + (e - s) / 2;
    // left part sorting
    merge_sort(vec, s, mid);

    // right part sorting 
    merge_sort(vec, mid + 1, e);

    //merge
    return merge(vec, s, e);
}

int main() {
    std::vector<int> vec{7, 93, 2, 0, 5, 1};
    std::cout << "Before Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    merge_sort(vec, 0, vec.size() - 1);
    std::cout << "After Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}