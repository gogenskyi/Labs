#include <random>
#include <algorithm>
#include <iostream>
#define SIZE 32

namespace exercise2 {
    int ex2_main();
}

bool binary_search(int*& arr,const int &target) {
    auto left = 0;
    auto right =  SIZE - 1;
    while (left <= right) {
        auto mid = (left + right) / 2;
        if (*(arr + mid) == target) {
            return true;
        }
        if (*(arr + mid) > target) {
            right = mid - 1;
        }
        if (*(arr + mid) < target) {
            left = mid + 1;
        }
    }
    return false;
}

void fill_array(int* arr) {
    for (int i = 0; i < 32; ++i) {
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> dist(-100, 100);
        *(arr + i) = dist(gen);
    }
    std::sort(arr, arr + SIZE);
}

int exercise1(int* arr) {
    int result = 0;
    for (int i = 0; i < SIZE && arr[i] < 0; ++i) {
        int target = -arr[i];
        if (binary_search(arr, target)) {
            for (int j = 0; j < SIZE; ++j) {
                if (arr[j] == target) {
                    ++result;
                }
            }
        }
    }
    return result;
}

int main() {
    auto arr = new int[SIZE];
    fill_array(arr);
    std::cout<<exercise1(arr);
    return 0;
}
