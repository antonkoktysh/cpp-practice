#include "ugly.h"
#include "bad.h"

class Spline::SplineImpl {
private:
    std::vector<double> x_;
    std::vector<double> y_;
    std::vector<double> y2_;

public:
    SplineImpl(std::vector<double>&& x, std::vector<double>&& y, double a, double b)
        : x_(std::move(x)), y_(std::move(y)), y2_(x_.size()) {
        const double* x_arg = x_.data();
        const double* y_arg = y_.data();
        size_t n = x_.size();
        double* y2_arg = y2_.data();
        int res = mySplineSnd(x_arg, y_arg, n, a, b, y2_arg);
        if (res == -2) {
            throw std::invalid_argument("");
        }
        if (res == -1) {
            throw std::bad_alloc();
        }
    }

    double Interpolate(double x) const {
        const double* xa = x_.data();
        const double* ya = y_.data();
        const double* y2a = y2_.data();
        size_t n = x_.size();
        double y1;
        int res = mySplintCube(xa, ya, y2a, n, x, &y1);
        if (res == -1) {
            throw std::runtime_error("");
        }
        return y1;
    }
};

Spline::Spline(std::vector<double> x, std::vector<double> y, double a, double b)
    : impl_(new SplineImpl(std::move(x), std::move(y), a, b)) {
}

double Spline::Interpolate(double x) const {
    return impl_->Interpolate(x);
}
Spline::~Spline() {
}