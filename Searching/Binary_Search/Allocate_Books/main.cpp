#include<iostream>
#include<vector>

bool isPossible(std::vector<int> arr, int n, int m, int mid) {
    int student{1};
    int pageSum{0};

    for(int i = 0; i < n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else {
            student++;
            if(student > m) return false;
            i--;
            pageSum = 0;
        }
    }
    return true;
}

int allocateBooks(std::vector<int> arr, int n, int m) {
    int start{0};
    
    int sum{0};
    for(int i : arr) sum += i;
    int end = sum;

    int ans{-1};
    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    std::vector<int> arr {5, 17, 100, 11};
    int n = arr.size();
    int m = 4;
    int ans = allocateBooks(arr, n, m);
    std::cout << ans << std::endl;

    return 0;
}

// Test Cases :-

// {10, 20, 30, 40} m = 2;
// ans = 60;

// {5, 17, 100, 11} m = 4;
// ans = 100;

// {12, 34, 67, 90} m = 2;
// ans = 113;