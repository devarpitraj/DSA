#include<iostream>
#include<vector>

int main() {
    std::vector<std::vector<int>> vec;

    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++)
    //         vec[i][j] = 0;
    // }
    // cannot do this way in case of vector<vector>

    for(int i = 0; i < 3; i++) {
        std::vector<int> row(3, 1);
        vec.push_back(row);
    }

    for(auto i : vec) {
        for(auto j : i) 
            std::cout << j << " ";
        std::cout << std::endl;
    }

    std::cout << vec[1][0];

    std::vector<int> vec2(2, 1);
    std::cout << vec2[0];
    return 0;
}