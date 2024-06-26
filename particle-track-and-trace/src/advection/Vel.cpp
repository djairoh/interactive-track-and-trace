#include "Vel.h"
#include <stdexcept>
#include <iomanip>

using namespace std;

Vel::Vel(double u, double v) : u(u), v(v) {}

Vel::Vel(const std::pair<double, double>& p) : u(p.first), v(p.second) {}

Vel& Vel::operator=(const std::pair<double, double>& p) {
    u = p.first;
    v = p.second;
    return *this;
}

Vel Vel::operator+(const Vel& other) const {
    return Vel(u + other.u, v + other.v);
}

Vel& Vel::operator+=(const Vel& other) {
    u += other.u;
    v += other.v;
    return *this;
}

template<typename Scalar>
Vel Vel::operator/(Scalar scalar) const {
    if (scalar == 0) throw std::runtime_error("Division by zero");
    return Vel(u / scalar, v / scalar);
}

std::ostream& operator<<(ostream& os, const Vel& vel) {
    os << "(";
    os << fixed << setprecision(2) << setw(5) << vel.u;
    os << ", ";
    os << fixed << setprecision(2) << setw(5) << vel.v;
    os << ")";
    return os;
}