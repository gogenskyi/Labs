#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>

void ex2(const char* sentence) {
    std::vector<std::unique_ptr<std::string>> arr;
    std::string word;
    for (const char* p = sentence; *p != '\0'; p++) {
        if (*p == ' ' || *p == '\t') {
            if (!word.empty()) {
                arr.push_back(std::make_unique<std::string>(word));
                word.clear();
            }
        }
        else {
            word += *p;
        }
    }
    if (!word.empty()) {
        arr.push_back(std::make_unique<std::string>(word));
    }
    std::sort(arr.begin(), arr.end(),
        [](const auto& a, const auto& b) {
            return *a < *b;
        });
    for (const auto& p : arr) {
        std::cout << *p << '\n';
    }
}