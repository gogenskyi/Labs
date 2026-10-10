#include <iostream>
#include <cmath>
#define FOR

double start = 0;
double end = 1;
int count = 13;

template<typename T>
static void printValues(T x,T y) {
    std::cout<<"x = "<<x
    <<std::endl<<"y = "<<y<<std::endl<<std::endl;
}

static int Fac(const int number) {
    if (number > 1) {
        return number * Fac(number - 1);
    }
    return number;
}

double Intergral() {
    double step = (end - start) / (count - 1);
    double x = 0.0;
    double y = 0.0;
    double result = 0;
#ifdef FOR
    for (double i = start;i <= end;i += step) {
        x = i;
        y = exp(-x) + sin(2*x) - 1.5*x*x;
        result += step * y;
    }
#endif
#ifdef WHILE
    double i = 0;
    while (i <= end) {
        x = i;
        y = exp(-x) + sin(2*x) - 1.5*x*x;
        result += step * y;
        i += step;
    }
#endif
#ifdef DOWHILE
    do {
        x = i;
        y = exp(-x) + sin(2 * x) - 1.5 * x * x;
        result += step * y;
        i += step;
    } while (i <= end);
#endif
    std::cout<<result<<std::endl;
    return result;
}

double Exercise2(const double x,const double eps) {
    if (x == 0 || std::abs(x) >= 1)
        throw std::invalid_argument("Помилка: x має задовольняти умову 0 < |x| < 1.");
    if (eps <= 0)
        throw std::invalid_argument("Помилка: eps має бути більше 0.");
    double x2 = x * x;
    double term = 1.0;
    double S = term;
    int k = 0;

    while (std::abs(term) >= eps) {
        term *= (2.0 * k + 3.0) / ((k + 1.0) * (2.0 * k + 1.0)) * x2;
        S += term;
        ++k;
    }
    return S;
}

int main() {
    std::cout<<Exercise2(0.8,0.0001)<<std::endl;
    return 0;
}
