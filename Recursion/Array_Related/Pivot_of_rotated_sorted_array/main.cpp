#include<iostream>
#include<vector>

int get_pivot(std::vector<int>& vec, int s, int e) {
    if(s >= e) return s;
    int mid = s + (e - s) / 2;
    if(vec[mid] >= vec[0]) return get_pivot(vec, mid + 1, e);
    else return get_pivot(vec, s, mid);

    return s;
}

int main() {
    std::vector<int> vec{1};
    
    int pi = get_pivot(vec, 0, vec.size() - 1);

    std::cout << "Pivot of rotatiion : " << pi << std::endl;
    return 0;
}