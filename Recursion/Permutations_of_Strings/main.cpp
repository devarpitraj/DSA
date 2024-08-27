#include<iostream>
#include<vector>
#include<string>

void solve(std::string str, int index, std::vector<std::string>& ans) {
    //base case
    if(index >= str.length()) {
        ans.push_back(str);
        return;
    }

    for(int i = index; i < str.length(); i++) {
        std::swap(str[index], str[i]);
        solve(str, index + 1, ans);
        // std::swap(str[index], str[i]);
        // this is needed to be done when
        //  we pass "str" by reference
    }
}

std::vector<std::string> perm(std::string str) {
    std::vector<std::string> ans;
    // std::string output;

    solve(str, 0, ans);

    return ans;
}

int main() {
    std::string str{"abc"};

    std::vector<std::string> ans = perm(str);

    for(auto i: ans) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}