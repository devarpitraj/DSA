#include<iostream>
#include<vector>
#include<algorithm>

class Fibonacci {
    private:
        std::vector<int> vec;
    public:
        Fibonacci() {
            int n{10};
            while(n--) {
                vec.push_back(-1);
            }
        }
        int fib(int n) {
            if(n < 0) {
                std::cerr << "Illegal Input" << std::endl;
                return -1;
            }
            if(n <= 1) {
                vec.at(n) = n;
                return n;
            } else {
                if(vec.at(n - 2) == -1) vec.at(n - 2) = fib(n - 2);
                if(vec.at(n - 1) == -1) vec.at(n - 1) = fib(n - 1);
                return vec.at(n - 2) + vec.at(n - 1);
            }
        }
};

int main() {
    Fibonacci obj;

    int ans{}, term{};
    std::cout << "Enter term:" ;
    std::cin >> term;
    ans = obj.fib(term - 1);

    std::cout << ans << std::endl;

    return 0;
}