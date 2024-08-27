#include<iostream>

int main() {
    int a, b;
    std::cout << "Enter base: ";
    std::cin >> a;
    std::cout << "Enter exponent: ";
    std::cin >> b;

    long long res = 1;
    int n = b, m = a;
    while(b > 0) {
        if(b & 1)
            res = res * a;
        a = 1LL * a * a;
        b >>= 1;
    }

    std::cout << m << " ^ " << n << " is " << res << std::endl;

    return 0;
}