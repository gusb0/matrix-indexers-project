#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<int>(c)) {
        std::srand(std::time(nullptr));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                data[i][j] = rand() % 9 + 1;
    }

    double operator[](int row) const {
        if (row < 0 || row >= rows)
            throw std::out_of_range("Невірний індекс");

        double sumSq = 0;
        for (int j = 0; j < cols; ++j)
            sumSq += data[row][j] * data[row][j];

        return std::sqrt(sumSq / cols);
    }

    int totalSum() const {
        int sum = 0;
        for (const auto& row : data)
            for (int val : row)
                sum += val;
        return sum;
    }

    void print() const {
        for (const auto& row : data) {
            for (int val : row)
                std::cout << val << "\t";
            std::cout << "\n";
        }
    }
};

int main() {
    Matrix m(3, 4);
    m.print();

    std::cout << "\nСередньоквадратичні значення по рядках:\n";
    for (int i = 0; i < 3; ++i)
        std::cout << "Рядок " << i << ": " << m[i] << "\n";

    std::cout << "\nСума всіх елементів: " << m.totalSum() << "\n";

    return 0;
}
