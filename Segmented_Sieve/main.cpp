#include<iostream>
#include<vector>
#include<math.h>

std::vector<long long> generate_primes(int n) {
    std::vector<int> ds(n + 1, 1);
    ds[0] = ds[1] = 0;
    for(auto i = 2; i * i <= n; i++) {
        if(ds[i] == 1) {
            for(int j = i * i; j <= n; j += i) 
                ds[j] = 0;
        }
    }

    std::vector<long long> primes;
    for(int i = 0; i < ds.size(); i++) {
        if(ds[i] == 1) primes.push_back(i);
    }
    return primes;
}

std::vector<long long> mark(std::vector<long long> primes, long long l , long long r) {
    // create a vector of (r - l + 1) size with all as 1
    std::vector<int> isPrime(r - l + 1, 1);
    if(l == 1) isPrime[0] = 0;

    // traverse the primes array
    for(auto i : primes) {
        // find the firstMultiple of i in range [l, r]
        long long firstMultiple = (l / i) * i;
        if(firstMultiple < l) firstMultiple += i;

        // start from firstMultiple to r and mark the multiples
        // of i as 0
        for(auto j = std::max(firstMultiple, i * i); j <= r; j += i) {
            // use (j - l) to shift index in range [l, r]
            isPrime[j - l] = 0;
        }
    }

    std::vector<long long> ans;
    for(auto i = 0; i < isPrime.size(); i++) {
        if(isPrime[i] == 1) ans.push_back(i + l);
    }
    return ans;
}

int main() {
    long long l, r;
    std::cout << "Enter range: ";
    std::cin >> l >> r;

    // generate primes <= floor(sqrt(r))
    std::vector<long long> primes = generate_primes(sqrt(r));
    // for(int i : primes) std::cout << i << " ";

    // create a vector of (r - l + 1) size with all 1
    //std::vector<int> isPrime(r - l + 1, 1);

    //mark the multiples of primes as 0 in isPrime
    std::vector<long long> ans = mark(primes, l, r);

    if(ans.size() == 0) std::cout << "No primes between " << l << " and " << r << std::endl;
    else 
    {
        std::cout << "Primes between " << l << " and " << r << " are: ";
        for(int i : ans) std::cout << i << " ";
    }

    return 0;
}