#include<iostream>

int nCr(int n, int r) {
    if(n < 0 || r < 0) {
        std::cerr << "Illegal input" << std::endl;
        return -1;
    }
    if(r > n) {
        std::cerr << "r can't be greater than n" << std::endl;
        return -2;
    }
    if(r == 0 || n == r) return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main() {
    int n{}, r{};
    std::cout << "Enter n and r:";
    std::cin >> n >> r;
    std::cout << nCr(n, r) << std::endl;

    return 0;
}