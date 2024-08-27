// Print a given digit in words
// e.g.
// 304 -> Three Zero Four

#include<iostream>
#include<vector>
#include<string>

class Say {
    public:
        std::vector<std::string> map {"Zero", "One", "Two", "Three", "Four", "Five",
                                    "Six", "Seven", "Eight", "Nine"};

        void say_digits(int n) {
            if(n == 0) return;

            int digit = n % 10;
            n = n / 10;
            say_digits(n);

            std::cout << map[digit] << " ";
            return;
        }
};


int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;



    Say obj;
    obj.say_digits(n);

    return 0;
}