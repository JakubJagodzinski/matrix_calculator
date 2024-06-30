#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdarg>
#include <vector>
#include <cmath>

using namespace std;

int fit_index(int index, int value);

class Matrix {
private:
    vector<vector<double>> data;
    int width;
    int height;

    void destroy_data() {
        for (int y = 0; y < this->height; ++y) {
            this->data[y].clear();
        }
        this->data.clear();
        this->width = 0;
        this->height = 0;
    }

    void create_data(int initial_width, int initial_height) {
        this->width = initial_width;
        this->height = initial_height;
        for (int y = 0; y < this->height; ++y) {
            vector<double> new_row;
            for (int x = 0; x < this->width; ++x) {
                new_row.push_back(0);
            }
            this->data.push_back(new_row);
        }
    }

    void copy_data(const Matrix &matrix) {
        for (int y = 0; y < matrix.height; ++y) {
            for (int x = 0; x < matrix.width; ++x) {
                this->data[y][x] = matrix.data[y][x];
            }
        }
    }

    [[nodiscard]] Matrix get_sub_matrix(int column_to_remove) const {
        Matrix sub_matrix(this->width - 1, this->height - 1);
        for (int y = 1; y < this->height; ++y) {
            int sub_matrix_row = y - 1;
            for (int x = 0; x < this->width; ++x) {
                if (x != column_to_remove) {
                    sub_matrix.data[sub_matrix_row][x > column_to_remove ? x - 1 : x] = this->data[y][x];
                }
            }
        }
        return sub_matrix;
    }

public:
    Matrix(int initial_width = 5, int initial_height = 5) {
        if (initial_width < 1 or initial_height < 1) {
            cout << "Incorrect matrix dimensions" << endl;
            exit(1);
        }
        this->create_data((int) initial_width, (int) initial_height);
    }

    Matrix(const Matrix &matrix) {
        this->create_data(matrix.width, matrix.height);
        this->copy_data(matrix);
    }

    ~Matrix() {
        this->destroy_data();
    }

    void enter_data() {
        cout << "Enter data:" << endl;
        for (int y = 0; y < this->height; ++y) {
            for (int x = 0; x < this->width; ++x) {
                cout << "(" << x << "," << y << "):";
                double number;
                if (scanf("%lf", &number) != 1) {
                    cout << "Incorrect input" << endl;
                    return;
                }
                this->data[y][x] = number;
            }
        }
    }

    vector<double> &operator[](int index) {
        return this->data[index];
    }

    const vector<double> &operator[](int index) const {
        return this->data[index];
    }

    Matrix &operator=(const Matrix &matrix) {
        if (this != &matrix) {
            this->destroy_data();
            this->create_data(matrix.width, matrix.height);
            this->copy_data(matrix);
        }
        return *this;
    }

    bool operator==(const Matrix &matrix) const {
        if (this->width != this->height or !(this->width == matrix.width and this->height == matrix.height)) {
            return false;
        }
        for (int y = 0; y < this->height; ++y) {
            for (int x = 0; x < this->width; ++x) {
                if (this->data[y][x] != matrix.data[y][x]) {
                    return false;
                }
            }
        }
        return true;
    }

    Matrix operator+(const Matrix &matrix) const {
        if ((this->width != matrix.width) or (this->height != matrix.height)) {
            cout << "Couldn't perform addition - different matrix dimensions." << endl;
            return *this;
        }
        Matrix result_matrix = *this;
        for (int y = 0; y < result_matrix.height; ++y) {
            for (int x = 0; x < result_matrix.width; ++x) {
                result_matrix.data[y][x] += matrix.data[y][x];
            }
        }
        return result_matrix;
    }

    Matrix &operator+=(const Matrix &matrix) {
        *this = this->operator+(matrix);
        return *this;
    }

    Matrix &operator++() {
        for (int y = 0; y < this->height; ++y) {
            for (int x = 0; x < this->width; ++x) {
                ++this->data[y][x];
            }
        }
        return *this;
    }

    Matrix operator++(int) {
        Matrix old_matrix(*this);
        this->operator++();
        return old_matrix;
    }

    Matrix operator-() const {
        Matrix result_matrix(*this);
        for (int y = 0; y < this->height; ++y) {
            for (int x = 0; x < this->width; ++x) {
                result_matrix.data[y][x] = -this->data[y][x];
            }
        }
        return result_matrix;
    }

    Matrix operator-(const Matrix &matrix) const {
        if ((this->width != matrix.width) or (this->height != matrix.height)) {
            cout << "Couldn't perform subtraction - different matrix dimensions." << endl;
            return *this;
        }
        Matrix result_matrix(*this);
        for (int y = 0; y < result_matrix.height; ++y) {
            for (int x = 0; x < result_matrix.width; ++x) {
                result_matrix.data[y][x] -= matrix.data[y][x];
            }
        }
        return result_matrix;
    }

    Matrix &operator-=(const Matrix &matrix) {
        *this = this->operator-(matrix);
        return *this;
    }

    Matrix &operator--() {
        for (int y = 0; y < this->height; ++y) {
            for (int x = 0; x < this->width; ++x) {
                --this->data[y][x];
            }
        }
        return *this;
    }

    Matrix operator--(int) {
        Matrix old_matrix(*this);
        this->operator--();
        return old_matrix;
    }

    Matrix operator*(double value) const {
        Matrix result_matrix(*this);
        for (int y = 0; y < this->height; ++y) {
            for (int x = 0; x < this->width; ++x) {
                result_matrix.data[y][x] *= value;
            }
        }
        return result_matrix;
    }

    Matrix &operator*=(double value) {
        *this = this->operator*(value);
        return *this;
    }

    friend Matrix operator*(double value, const Matrix &matrix) {
        return matrix.operator*(value);
    }

    Matrix operator*(const Matrix &matrix) const {
        if (this->width != matrix.height) {
            cout << "Couldn't perform multiplication - wrong matrix dimensions" << endl;
            return *this;
        }
        Matrix result_matrix = Matrix(this->width, this->height);
        for (int y = 0; y < result_matrix.height; ++y) {
            for (int x = 0; x < result_matrix.width; ++x) {
                for (int k = 0; k < result_matrix.width; ++k) {
                    result_matrix.data[y][x] += this->data[y][k] * matrix.data[k][x];
                }
            }
        }
        return result_matrix;
    }

    Matrix &operator*=(const Matrix &matrix) {
        *this = this->operator*(matrix);
        return *this;
    }

    [[nodiscard]] Matrix transposed() const {
        Matrix result_matrix = Matrix(this->height, this->width);
        for (int y = 0; y < this->height; ++y) {
            for (int x = 0; x < this->width; ++x) {
                result_matrix.data[x][y] = this->data[y][x];
            }
        }
        return result_matrix;
    }

    void transpose() {
        *this = this->transposed();
    }

    friend ostream &operator<<(ostream &os, const Matrix &matrix) {
        for (int y = 0; y < matrix.height; ++y) {
            for (int x = 0; x < matrix.width; ++x) {
                os << setw(3) << matrix.data[y][x] << ' ';
            }
            cout << endl;
        }
        return os;
    }

    void fill_row(int row, unsigned int number_of_variables, ...) {
        row = fit_index(row, this->height - 1);
        va_list arg;
        va_start(arg, number_of_variables);
        for (int x = 0; x < (int) number_of_variables; ++x) {
            this->data[row][x] = va_arg(arg, double);
        }
        va_end(arg);
    }

    void fill_column(int column, unsigned int number_of_variables, ...) {
        column = fit_index(column, this->width - 1);
        va_list arg;
        va_start(arg, number_of_variables);
        for (int y = 0; y < (int) number_of_variables; ++y) {
            this->data[y][column] = va_arg(arg, double);
        }
        va_end(arg);
    }

    void add_row_to_row(int dst_index, int src_index) {
        dst_index = fit_index(dst_index, this->height - 1);
        src_index = fit_index(src_index, this->height - 1);
        for (int x = 0; x < this->width; ++x) {
            this->data[dst_index][x] += this->data[src_index][x];
        }
    }

    void add_column_to_column(int dst_index, int src_index) {
        dst_index = fit_index(dst_index, this->width - 1);
        src_index = fit_index(src_index, this->width - 1);
        for (int y = 0; y < this->height; ++y) {
            this->data[y][dst_index] += this->data[y][src_index];
        }
    }

    void add_row(int position) {
        position = fit_index(position, this->height);
        vector<double> new_row;
        for (int x = 0; x < this->width; ++x) {
            new_row.push_back(0);
        }
        this->data.insert(this->data.begin() + position, new_row);
        ++this->height;
    }

    void add_column(int position) {
        position = fit_index(position, this->width);
        for (int y = 0; y < this->height; ++y) {
            this->data[y].insert(this->data[y].begin() + position, 0);
        }
        ++this->width;
    }

    void delete_row(int position) {
        position = fit_index(position, this->height);
        this->data.erase(this->data.begin() + position);
        --this->height;
    }

    void delete_column(int position) {
        position = fit_index(position, this->height);
        for (int y = 0; y < this->height; ++y) {
            this->data[y].erase(this->data[y].begin() + position);
        }
        --this->width;
    }

    void swap_rows(int first, int second) {
        first = fit_index(first, this->height - 1);
        second = fit_index(first, this->height - 1);
        if (first != second) {
            vector<double> temp = this->data[first];
            this->data[first] = this->data[second];
            this->data[second] = temp;
        }
    }

    void swap_columns(int first, int second) {
        first = fit_index(first, this->width - 1);
        second = fit_index(second, this->width - 1);
        if (first != second) {
            for (int y = 0; y < this->height; ++y) {
                double temp = this->data[y][first];
                this->data[y][first] = this->data[y][second];
                this->data[y][second] = temp;
            }
        }
    }

    [[nodiscard]] bool is_square() const {
        return this->width == this->height;
    }

    [[nodiscard]] bool is_symmetrical() const {
        return this->transposed().data == this->data;
    }

    [[nodiscard]] bool is_anti_symmetrical() const {
        return this->transposed().data == (-(*this)).data;
    }

    [[nodiscard]] bool is_diagonal() const {
        if (!this->is_square()) {
            cout << "Matrix is not square." << endl;
            return false;
        }
        for (int y = 0; y < this->height; ++y) {
            for (int x = 0; x < this->width; ++x) {
                if (y != x and this->data[y][x] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    [[nodiscard]] bool is_identity() const {
        if (!this->is_square()) {
            cout << "Matrix is not square." << endl;
            return false;
        }
        for (int y = 0; y < this->height; ++y) {
            for (int x = 0; x < this->width; ++x) {
                if ((y == x and this->data[y][x] != 1) or (y != x and this->data[y][x] != 0)) {
                    return false;
                }
            }
        }
        return true;
    }

    [[nodiscard]] double trace() const {
        if (!this->is_square()) {
            cout << "Matrix is not square." << endl;
            return 0;
        }
        double trace = 0;
        for (int y = 0; y < this->height; ++y) {
            trace += this->data[y][y];
        }
        return trace;
    }

    [[nodiscard]] double determinant_Gauss() const {
        if (!this->is_square()) {
            cout << "Matrix is not square." << endl;
            return 0;
        }
        Matrix temp(*this);
        double determinant = 1;
        for (int y = 0; y < this->height; ++y) {
            int non_zero_row = y;
            while (non_zero_row < this->height and fabs(temp.data[non_zero_row][y]) < 1e-9) {
                ++non_zero_row;
            }
            if (non_zero_row == this->height) {
                return 0;
            }
            if (non_zero_row != y) {
                temp.swap_rows(y, non_zero_row);
                determinant *= -1;
            }
            for (int yy = y + 1; yy < this->height; ++yy) {
                double factor = temp.data[yy][y] / temp.data[y][y];
                for (int x = y; x < this->width; ++x) {
                    temp.data[yy][x] -= factor * temp.data[y][x];
                }
            }
            determinant *= temp.data[y][y];
        }
        return determinant;
    }

    [[nodiscard]] double determinant_laplace() const {
        if (!this->is_square()) {
            cout << "Matrix is not square" << endl;
            return 0;
        }
        if (this->width == 1) {
            return data[0][0];
        }
        double det = 0;
        for (int x = 0; x < this->width; ++x) {
            Matrix sub_matrix = get_sub_matrix(x);
            det += (x % 2 == 0 ? 1 : -1) * data[0][x] * sub_matrix.determinant_laplace();
        }
        return det;
    }

    [[nodiscard]] Matrix inversed() const {
        if (!this->is_square()) {
            cout << "Matrix is not square." << endl;
            return *this;
        }
        Matrix identity_matrix(this->width, this->height);
        for (int y = 0; y < this->height; ++y) {
            identity_matrix.data[y][y] = 1;
        }
        Matrix temp(*this);
        for (int y = 0; y < this->height; ++y) {
            int non_zero_row = y;
            while (non_zero_row < this->height and fabs(temp.data[non_zero_row][y]) < 1e-9) {
                ++non_zero_row;
            }
            if (non_zero_row == this->height) {
                cout << "Matrix is not invertible (singular)." << endl;
                return *this;
            }
            if (non_zero_row != y) {
                temp.swap_rows(y, non_zero_row);
                identity_matrix.swap_rows(y, non_zero_row);
            }
            double scale = temp.data[y][y];
            for (int x = 0; x < this->width; ++x) {
                temp.data[y][x] /= scale;
                identity_matrix.data[y][x] /= scale;
            }
            for (int yy = 0; yy < this->height; ++yy) {
                if (yy != y) {
                    double factor = temp.data[yy][y];
                    for (int x = 0; x < this->width; ++x) {
                        temp.data[yy][x] -= factor * temp.data[y][x];
                        identity_matrix.data[yy][x] -= factor * identity_matrix.data[y][x];
                    }
                }
            }
        }
        return identity_matrix;
    }

    void inverse() {
        *this = this->inversed();
    }
};

int fit_index(int index, int value) {
    return index < 0 ? 0 : (index > value ? value : index);
}

#endif
