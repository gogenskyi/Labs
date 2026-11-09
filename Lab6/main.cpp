#include <iostream>
#include <memory>

#include "ex2.h"

int words_count(const std::unique_ptr<char[]> &line) {
    auto count = 0;
    for (int i = 0;line[i] != '\0';i++) {
        if (line[i] == ' ' && line[i + 1] != ' ') {
            count++;
        }
    }
    return count + 1;
}

int main() {
    constexpr auto size = 1000;
    const auto line = std::make_unique<char[]>(size);
    std::cin.getline(line.get(), size);
    // std::cout<<"there "<<words_count(std::move(line))<<" words"<<std::endl;
    ex2(line.get());
    return 0;

}
