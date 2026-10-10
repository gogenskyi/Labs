#include <iostream>
#include <cmath>

template<typename T>
double CalculateEX1(const T x,const T y,const T z) {
    if (z > 1 || z < -1) {
        throw std::runtime_error("Змінна z не проходить по ОДЗ");
    }
    const double left_expression = (10*(cbrt(x)+pow(x,y+2)));
    if (left_expression < 0) {
        throw std::runtime_error("Відʼємне число не можна підносити до корення парного степення");
    }
    return std::sqrt(left_expression) * ((pow(asin(z), 2) - (fabs(x - y))));
}

template<typename T>
double CalculateEX2(const T z) {
    T x;
    if (z < 0) {
        x = z;
    }
    else {
        x = std::sin(z);
    }
    return ((2.0/3.0)*std::pow(std::sin(x),2) - 0.75*std::pow(std::cos(x),2));
}

int main() {
    double x;
    std::cout<<"Enter x:\t"<<std::endl;
    std::cin>>x;
    std::cout<<CalculateEX2(x)<<std::endl;
    std::cout<<"Enter x:\t"<<std::endl;
    std::cin>>x;
    std::cout<<CalculateEX2(x)<<std::endl;
    return 0;
}
