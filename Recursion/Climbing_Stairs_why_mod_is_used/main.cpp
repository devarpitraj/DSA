// Problem statement
// You have been given a number of stairs. Initially,
//  you are at the 0th stair, and you need to reach the Nth stair.

// Each time, you can climb either one step or two steps.

// You are supposed to return the number of distinct ways 
// you can climb from the 0th step to the Nth step.

// code

#include <bits/stdc++.h> 

int countDistinctWays(int nStairs) {
    //  Write your code here.
    int mod =1000000007;
    int prev = 1, ans = 1;
    if(nStairs == 0) return 1;
    if(nStairs == 1) return 1;

    for(int i = 2; i <= nStairs; i++) {
        int curr = (ans + prev) % mod;
        prev = ans;
        ans = curr;
    }
    // In this code, mod is used to ensure that intermediate results 
    // and the final result stay within bounds. Specifically, 
    // after performing each arithmetic operation (+, -, *, etc.), the result is taken modulo mod. 
    // This helps prevent the result from becoming too large and potentially causing overflow issues.
    return ans;
}

int main() {
    int num;
    std::cout << "Enter no. of stair: ";
    std::cin >> num;

    int ans = countDistinctWays(num);

    std::cout << "No. of ways to climb " << num << " stairs: " << ans << std::endl;

    return 0;
}