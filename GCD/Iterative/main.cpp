#include<iostream>

int gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;

    while(a != b) {
        if(a > b) a -= b;
        else b -= a;
    }
    return a;
}

int main() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    int ans = gcd(a, b);
    std::cout << "GCD of " << a << " and " << b << " is: " << ans << std::endl;

    return 0;
}