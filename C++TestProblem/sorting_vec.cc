#include <iostream>
#include <vector>
#include <algorithm>

void sortDescending(int* arr, int num_elem) {
    std::vector<int> vec(arr, arr + num_elem);
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    int i = 0;
    for (const auto& e : vec) {
        arr[i++] = e;
    }
}

int main() {
    int a[5] = {5, -3, 1, 9, 2};
    int num_elem = 5;

    sortDescending(a, num_elem);

    for (int i = 0; i < num_elem; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
