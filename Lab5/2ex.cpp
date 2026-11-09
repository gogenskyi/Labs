#include <iostream>

static void ex2() {
    std::string s1;
    std::string s2;

    std::cin>>s1;
    std::cin>>s2;

    if (s2.empty() || s1.size() > 100 || s2.size() > 100 || s1.empty()) {
        throw std::invalid_argument("Exception");
    }

    auto pos = 0;
    while ((pos = s1.find(s2, pos)) != std::string::npos) {
        s1.erase(pos, s2.length());
    }
    std::cout<<s1<<std::endl;
}