#include<iostream>
#include<queue>

int solve(int* arr, int n, int k) {
    std::queue<int> maxi;
    std::queue<int> mini;

    // process 1st window
    for(int i = 0; i < k; i++) {
        while(!maxi.empty() && arr[maxi.front()] <= arr[i])
            maxi.pop();
        
        while(!mini.empty() && arr[mini.front()] >= arr[i])
            mini.pop();

        maxi.push(i);
        mini.push(i);
    }

    // add sum to ans
    int ans = arr[maxi.front()] + arr[mini.front()];

    // process remaining windows
    for(int i = k; i < n; i++) {
        // removal
        while(i - maxi.front() >= k) maxi.pop();
        while(i - mini.front() >= k) mini.pop();

        // addition
        while(!maxi.empty() && arr[maxi.front()] <= arr[i])
            maxi.pop();

        while(!mini.empty() && arr[mini.front()] >= arr[i])
            mini.pop();

        maxi.push(i);
        mini.push(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}

int main() {
    int arr[7] {2, 5, -1, 7, -3, -1, 2};
    int k = 4;

    std::cout << "Sum : " << solve(arr, 7, k) << std::endl;

    return 0;
}