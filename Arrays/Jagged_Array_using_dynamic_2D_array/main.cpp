#include<iostream>

// A jagged array is an array of arrays such that member arrays can be of different sizes,
// in 2D array terms for each row we can have a variable number of columns.
// These types of arrays are also known as Jagged arrays. 

int main() {
    int rows{};
    std::cout << "Enter no. of rows: ";
    std::cin >> rows;

    int** arr = new int*[rows];
    
    int* sizes = new int[rows];
    for(int i = 0; i < rows; i++) {
        int cols{};
        std::cout << "Enter no. of cols for " << i << "th row: ";
        std::cin >> cols;
        sizes[i] = cols;

        arr[i] = new int[cols];
    }

    //input
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < sizes[i]; j++) {
            std::cin >> arr[i][j];
        }
    }

    //output
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < sizes[i]; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < rows; i++) {
        delete []arr[i];
    }

    delete []sizes;
    delete []arr;

    return 0;

}