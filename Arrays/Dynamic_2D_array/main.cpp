#include<iostream>

int main() {

    int row{};
    int col{};

    std::cout << "Enter no. of rows: ";
    std::cin >> row;
    std::cout << "Enter no. of columns: ";
    std::cin >> col;

    // allocate memory  for row no. of arrays in the array
    int** arr = new int*[row];
    // allocate the i^th array the a col-sized array
    for(int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }

    // input
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            std::cin >> arr[i][j];
    }

    // output
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }

    // deleting allocated memory
    // first the col-sized arrays
    for(int i = 0; i< row; i++) {
        delete []arr[i];
    }
    // delete the row-sized array
    delete []arr;

    return 0;
}