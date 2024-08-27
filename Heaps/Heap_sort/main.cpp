#include<iostream>
#include<vector>

void heapify(int* arr, int n, int i) {
    // 1-indexed

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[largest] < arr[left]) largest = left;
    if(right <= n && arr[largest] < arr[right]) largest = right;

    if(largest != i) {
        std::swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n) {
    //1-indexed

    int size = n;

    while(size > 1) {
        //step1: swap root with last node
        std::swap(arr[1], arr[size]);

        //step2: decrease size
        size--;

        //step3: heapify root
        heapify(arr, size, 1);
    }
}

void heapify(std::vector<int>& vec, int size, int i) {
    // 0-indexed
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && vec[largest] < vec[left]) largest = left;
    if(right < size && vec[largest] < vec[right]) largest = right;

    if(largest != i) {
        std::swap(vec[largest], vec[i]);
        heapify(vec, size, largest);
    }
}

void heapSort(std::vector<int>& vec, int size) {
    // 0-indexed

    int n = size - 1;

    while(n > 0) {
        // step1: swap root with last node
        std::swap(vec[0], vec[n]);

        // step2 : decrease size
        n--;

        // step3 : heapify root
        heapify(vec, n, 0);
    }
}

int main() {

    // 1-indexed
    int arr[7] = {-1, 53, 56, 27, 95, 18, 45};
    int n = 6;

    std::cout << "Input Array : ";
    for(int i = 1; i <= n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // create max heap
    for(int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    heapSort(arr, n);

    std::cout << "Sorted Array : ";
    for(int i = 1; i <= n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    // 0-indexed
    std::vector<int> vec {64, 72, 19, 35, 27, 98};

    std::cout << "Input Vector : ";
    for(auto i : vec) std::cout << i << " ";
    std::cout << std::endl;

    // create max heap
    int size = vec.size();
    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(vec, size, i);
    }

    heapSort(vec, size);

    std::cout << "Sorted Vector : ";
    for(auto i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}