#include <iostream>
#include <string>
#include <vector>
#include "2ex.cpp"

int count_o(const std::vector<std::string> &name) {
    auto result = 0;
    for (auto &line : name) {
        for (auto &symbol : line) {
            if (symbol == 'O' || symbol == 'o') {
                result++;
            }
        }
    }
    return result;
}

int main() {
    std::vector<std::string> arr;
    std::string input;
    do {
        input.clear();
        std::cout<<"Enter your name (press 1 to continue) -> ";
        std::cin>>input;
        arr.push_back(input);
    }while (input != "1");
    std::cout<<std::endl<<"у вашому імені:\t"<<count_o(arr)<<"\t літер \'О\'"<<std::endl;
    return 0;
}
