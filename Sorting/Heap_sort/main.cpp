#include<iostream>
#include<vector>
#include<queue>

void heapify(std::vector<int>& vec, int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && vec[largest] < vec[left]) largest = left;
    if(right < size && vec[largest] < vec[right]) largest = right;

    if(largest != index) {
        std::swap(vec[largest], vec[index]);
        heapify(vec, size, largest);
    }
}

void heap_sort(std::vector<int>& vec, int size) {
    if(size == 1) return;

    std::swap(vec[0], vec[size - 1]);

    size--;

    heapify(vec, size, 0);

    heap_sort(vec, size);
}

void heapSort(std::vector<int>& vec) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for(int i : vec) minHeap.push(i);
    

    vec.clear();

    while(!minHeap.empty()) {
        vec.push_back(minHeap.top());
        minHeap.pop();
    }
}

int main() {
    std::vector<int> vec{98, 65, 28, 100, 64, 75, 101, 77, 98};

    std::cout << "Input Vector : ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    // heap implementation
    int size = vec.size();
    for(int i = size / 2 - 1; i >= 0; i--) heapify(vec, size, i);

    heap_sort(vec, size);

    std::cout << "Sorted Vector : ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    // using priority queue
    heapSort(vec);

    std::cout << "Sorted Vector : ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}