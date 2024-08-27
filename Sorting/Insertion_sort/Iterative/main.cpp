#include<iostream>
#include<vector>

void insertion_sort(std::vector<int>& arr) {
    int n = arr.size();
    int i = 1;
    while(i < n) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0)  {
            if(arr[j] > temp) {
                //shift ahead
                arr[j+1] = arr[j];
            } else break;
            j--;
        }
        arr[j+1] = temp;    //place arr[i] at its correct position
        i++;
    }

    // for(int i = 1; i < n; i++) {
    //     int temp = arr[i];
    //     int j{};
    //     for(j = i - 1; j >= 0; j--) {
    //         if(arr[j] > temp) arr[j+1] = arr[j];
    //         else break;
    //     }
    //     arr[j+1] = temp;
    // }
}

int main() {
    std::vector<int> arr{4, 8, 10, 1, 5, 10, 3};

    std::cout << "Before Sorting : ";
    for(int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    insertion_sort(arr);

    std::cout << "After Sorting : ";
    for(int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}