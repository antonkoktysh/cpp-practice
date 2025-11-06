#pragma once
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> matrix_;

public:
    Matrix(std::size_t rows, std::size_t cols)
        : matrix_(std::vector<std::vector<double>>(rows, std::vector<double>(cols))) {
    }

    Matrix(std::size_t size)
        : matrix_(std::vector<std::vector<double>>(size, std::vector<double>(size))) {
    }

    Matrix(const Matrix& matrix) {
        matrix_ = matrix.matrix_;
    }

    Matrix(const std::vector<std::vector<double>> matrix) : matrix_(matrix) {
    }

    std::size_t Rows() const {
        return matrix_.size();
    }

    std::size_t Columns() const {
        if (!matrix_.empty()) {
            return matrix_[0].size();
        }
        return 0;
    }

    double& operator()(std::size_t ind, std::size_t jnd) {
        return matrix_[ind][jnd];
    }

    double operator()(std::size_t ind, std::size_t jnd) const {
        return matrix_[ind][jnd];
    }

    Matrix& operator+=(Matrix rhs) {
        for (std::size_t ind = 0U; ind < Rows(); ++ind) {
            for (std::size_t jnd = 0U; jnd < Columns(); ++jnd) {
                matrix_[ind][jnd] += rhs(ind, jnd);
            }
        }
        return *this;
    }

    Matrix& operator-=(Matrix rhs) {
        for (std::size_t ind = 0U; ind < Rows(); ++ind) {
            for (std::size_t jnd = 0U; jnd < Columns(); ++jnd) {
                matrix_[ind][jnd] -= rhs(ind, jnd);
            }
        }
        return *this;
    }

    Matrix& operator*=(Matrix rhs) {
        Matrix result(Rows(), rhs.Columns());
        for (std::size_t ind = 0U; ind < Rows(); ++ind) {
            for (std::size_t jnd = 0U; jnd < result.Columns(); ++jnd) {
                double sum = 0;
                for (std::size_t knd = 0; knd < Columns(); ++knd) {
                    sum += matrix_[ind][knd] * rhs.matrix_[knd][jnd];
                }
                result.matrix_[ind][jnd] = sum;
            }
        }
        matrix_ = result.matrix_;
        return *this;
    }
};

Matrix Transpose(Matrix matrix) {
    Matrix transposed_matrix(matrix.Columns(), matrix.Rows());
    for (std::size_t ind = 0U; ind < matrix.Rows(); ++ind) {
        for (std::size_t jnd = 0U; jnd < matrix.Columns(); ++jnd) {
            transposed_matrix(jnd, ind) = matrix(ind, jnd);
        }
    }
    return transposed_matrix;
}

Matrix Identity(std::size_t size) {
    std::vector<std::vector<double>> identity_matrix(size, std::vector<double>(size));
    for (std::size_t ind = 0U; ind < size; ++ind) {
        identity_matrix[ind][ind] = 1;
    }
    return Matrix(identity_matrix);
}

Matrix operator-(Matrix lhs, Matrix rhs) {
    lhs -= rhs;
    return lhs;
}

Matrix operator+(Matrix lhs, Matrix rhs) {
    lhs += rhs;
    return lhs;
}

Matrix operator*(Matrix lhs, Matrix rhs) {
    lhs *= rhs;
    return lhs;
}