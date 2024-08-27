#include<iostream>

void TOH(int n, char a, char b, char c) {
    if(n > 0) {
        TOH(n-1, a, c, b);
        std::cout << "Moving disk from disk " << a << " to disk " << c << std::endl;
        TOH(n-1, b, a, c);
    }
}

int main() {
    int n{};
    std::cout << "Enter no. of disks: ";
    std::cin >> n;
    if(n < 1){
        std::cerr << "Illegal input" << std::endl;
        return -1;
    }

    char a, b, c;
    std::cout << "Enter name of source disk: " ;
    std::cin >> a;
    std::cout << "Enter name of destination disk: " ;
    std::cin >> c;
    std::cout << "Enter name of auxiliary disk: " ;
    std::cin >> b;

    std::cout << "The steps to move " << n << " disks from disk " << a << " to disk " << c
                << " are following: " << std::endl;
    TOH(n, a, b, c);

    return 0;
}