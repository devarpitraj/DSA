#include<iostream>
#include<math.h>

int expo(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;

    int ans = pow(a, b / 2);

    if(b & 1) return a * ans * ans;
    else return ans * ans;
}

int main() {
    int a, b;
    std::cout << "Enter base:";
    std::cin >> a;
    std::cout << "Enter exponent:";
    std::cin >> b;

    int ans = expo(a, b);

    std::cout << ans << std::endl;

    return 0;
}