//
// Created by Mykola on 09.11.2026.
//

#include "ex2.h"


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int CountWords(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "File opening error!\n";
        return -1;
    }

    std::string line;
    int count = 0;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;

        while (ss >> word) {
            count++;
        }
    }

    file.close();
    return count;
}

void Output(int count) {
    if (count >= 0) {
        std::cout << "Number of words: " << count << '\n';
    }
}

int ex2() {
    constexpr std::string filename = "text.txt";
    Output(CountWords(filename));

    return 0;
}

