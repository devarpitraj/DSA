#include<iostream>
#include<vector>

class CountPrime {
    public:
        int cntprime(int n) {
            int cnt{};
            std::vector<int> prime(n + 1, 1);

            prime[0] = prime[1] = 0;

            for(int i = 2; i * i <= n; i++) {
                if(prime[i] == 1) {
                    for(int j = i * i; j < n; j += i) {
                        prime[j] = 0;
                    }
                }
            }

            for(int i = 2; i < n; i++) {
                if(prime[i] == 1) cnt++;
            }

            return cnt;
        }
};

int main() {
    CountPrime obj;
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    int ans = obj.cntprime(n);

    std::cout << "Count of Prime Numbers less than " << n << " is: " << ans << std::endl;

    return 0;

}