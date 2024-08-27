#include<iostream>
#include<vector>
#include<algorithm>

void merge(std::vector<int>& vec, int s, int e, int maxele) {
    int mid = s + (e - s) / 2;

    int i = s, j = mid + 1, k = s;
    while(i <= mid && j <= e) {
        if((vec[i] % maxele) <= (vec[j] % maxele)) {
            vec[k] = vec[k] + (vec[i] % maxele) * maxele;
            k++;
            i++;
        } else {
            vec[k] = vec[k] + (vec[j] % maxele) * maxele;
            k++;
            j++;
        }
    }

    while(i <= mid) {
        vec[k] += (vec[i] % maxele) * maxele;
        k++;
        i++;
    }

    while(j <= e) {
        vec[k] += (vec[j] % maxele) * maxele;
        k++;
        j++;
    }

    //obtain sorted values
    for(int l = s; l <= e; l++)
        vec[l] = vec[l] / maxele;
}

void merge_sort(std::vector<int>& vec, int s, int e, int maxele) {
    if(s >= e) return;

    int mid = s + (e - s) / 2;

    //left sorting
    merge_sort(vec, s, mid, maxele);

    //right sorting
    merge_sort(vec, mid + 1, e, maxele);

    //merge
    merge(vec, s, e, maxele);
}

int main() {
    std::vector<int> vec{9, 3, 6, 1, 0};
    std::cout << "Before Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    //maxele > all elements in vec
    int maxele = *max_element(vec.begin(), vec.end()) + 1;
    
    merge_sort(vec, 0, vec.size() - 1, maxele);
    std::cout << "After Sorting: ";
    for(int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}