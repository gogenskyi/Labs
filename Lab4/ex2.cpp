#include <random>
#include <algorithm>
#include <iostream>
#define N 4

namespace exercise2 {

    void fill_matrix(int matrix[N][N]) {
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> dist(-10, 10);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = dist(gen);
            }
        }
    }
    void print_matrix(int matrix[N][N]) {
        for (auto i = 0;i < N;i++) {
            for (auto j = 0;j < N;j++) {
                std::cout<<matrix[i][j]<<'\t';
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
    void sort_by_row(int matrix[N][N]) {
        print_matrix(matrix);
        int row[N];
        for (auto i = 0;i < N;i++) {
            for (auto j = 0;j < N;j++) {
                row[j] = matrix[i][j];
            }
            std::ranges::sort(row);
            for (auto j = 0;j < N;j++) {
                matrix[i][j] = row[j];
            }
        }
        print_matrix(matrix);
    }


    int ex2_main() {
        int martix[N][N];
        fill_matrix(martix);
        sort_by_row(martix);
        return 0;
    }
}
