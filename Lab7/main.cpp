#include <iostream>
#include <numbers>
#include <cmath>

#include "ex2.h"

double Input(const std::string &line) {
    double val;
    std::cout<<"Enter "<<line<<std::endl;
    std::cin>>val;
    return val;
}

static double Count(const double &step,const double &start = 0,const double& end = std::numbers::pi) {
    return static_cast<int>((end - start) / step);
}

static double Integral(const double &step, const int N, double start = 0, double end = std::numbers::pi) {
    double x = start + step;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (sin(pow(x,3)) - 3 * x) * step;
        x += step;
    }
    return sum;
}

int main() {
    double step = Input("step");
    std::cout<<Integral(step,Count(step))<<std::endl;
    return 0;
}
