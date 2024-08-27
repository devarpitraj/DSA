#include<iostream>
#include<vector>

class Heap {
    public:
        int arr[1000];
        int size;

        Heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int data);
        void print();
        void remove();
};

void Heap::insert(int data) {
    size++;
    int index = size;

    // step1: insert at last index
    arr[index] = data;
    
    // step2: move it to its correct place
    while(index > 1) {
        int parent = index / 2;

        if(arr[parent] < arr[index]) {
            std::swap(arr[parent], arr[index]);
            index = parent;
        } else return;
    }
}

void Heap::print() {
    for(int i = 1; i <= size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Heap::remove() {
    if(size == 0) {
        std::cout << "Nothing to delete" << std::endl;
    }

    // step1: put last ele value in 1st node
    arr[1] = arr[size];

    // step2: delete last node
    size--;

    // step3: move root to its correct place
    int i = 1;
    while(i < size) {
        int leftindex = 2 * i;
        int rightindex = 2 * i + 1;

        // int index{};
        
        // if(leftindex <= size && rightindex <= size) {
        //     if(arr[leftindex] > arr[rightindex])
        //         index = leftindex;
        //     else index = rightindex; 
        // } else if(leftindex <= size && rightindex > size) {
        //     index = leftindex;
        // }

        // if(arr[index] > arr[i]) {
        //     std::swap(arr[index], arr[i]);
        //     i = index;
        // } else return;

        // Another method (similar to heapify algo)
        int index = i;

        if(leftindex <= size && arr[leftindex] > arr[index]) {
            index = leftindex;
        }
        if(rightindex <= size && arr[rightindex] > arr[index]) {
            index = rightindex;
        }

        if(index != i) {
            std::swap(arr[i], arr[index]);
            i = index;
        } else return;
    }
}

void heapify(int* arr, int n, int i) {
    // Max Heap 1-indexed
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        std::swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void print(int* arr, int n) {
    for(int i = 1; i <= n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void heapify(std::vector<int>& vec, int size, int i) {
    // Min Heap 0-indexed
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && vec[smallest] > vec[left]) smallest = left;
    if(right < size && vec[smallest] > vec[right]) smallest = right;

    if(smallest != i) {
        std::swap(vec[smallest], vec[i]);
        heapify(vec, size, smallest);
    }
}

int main() {
    Heap h;

    h.insert(100);
    h.insert(50);
    h.insert(10);
    h.insert(40);
    h.insert(30);
    h.insert(25); 

    h.print();

    h.remove();

    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }
    print(arr, n);

    std::vector<int> vec{54, 53, 55, 52, 50};
    int size = vec.size();
    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(vec, size, i);
    }

    for(auto i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}