#include<iostream>
#include<vector>

int PivotElem(std::vector<int> arr) {
    int start =  0;
    int end = arr.size() - 1;

    while(start < end) {
        int mid = start + (end - start) / 2;    //better than mid = (start + end) / 2;
        
        if(arr[mid] >= arr[0]) start = mid + 1;
        else end = mid;
    }
    return start;
}

int main() {
    std::vector<int> arr {7, 8, 9, 10, 2, 3,  5, 6};

    int index = PivotElem(arr);

    std::cout << "The index of pivot element is : " << index << std::endl;

    return 0;
}