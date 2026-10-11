#include <iostream>
#include <cmath>
#define FOR


constexpr double start = 0;
constexpr double end = 1;
constexpr int count = 13;

template<typename T>
static void printValues(T x,T y) {
    std::cout<<"x = "<<x
    <<std::endl<<"y = "<<y<<std::endl<<std::endl;
}

double f(double x) {
    return std::exp(-x) + std::sin(2 * x) - 1.5 * x * x;
}

double Integral() {
    if (count <= 0 || end <= start) {
        return 0.0;
    }

    const double step = (end - start) / count;
    double result = 0.0;

#if (defined(FOR) + defined(WHILE) + defined(DOWHILE)) != 1
#error "Define exactly one of FOR, WHILE, or DOWHILE"
#endif

#ifdef FOR
    for (int i = 0; i < count; ++i) {
        const double x = start + i * step;
        result += f(x) * step;
    }
#endif

#ifdef WHILE
    int i = 0;
    while (i < count) {
        const double x = start + i * step;
        result += f(x) * step;
        ++i;
    }
#endif

#ifdef DOWHILE
    int i = 0;
    do {
        const double x = start + i * step;
        result += f(x) * step;
        ++i;
    } while (i < count);
#endif

    std::cout << result << '\n';
    return result;
}

double Exercise2(const double x,const double eps) {
    if (x == 0 || std::abs(x) >= 1)
        throw std::invalid_argument("Помилка: x має задовольняти умову 0 < |x| < 1.");
    if (eps <= 0)
        throw std::invalid_argument("Помилка: eps має бути більше 0.");
    double term = 1.0;
    double S = term;
    int k = 0;

    while (std::abs(term) >= eps) {
        term *= (2.0 * k + 3) * x * x
              / ((k + 1) * (2.0 * k + 1));

        S += term;
        ++k;
    }
    return S;
}

int main() {
    std::cout<<Exercise2(0.5,0.00001)<<std::endl;
    return 0;
}
