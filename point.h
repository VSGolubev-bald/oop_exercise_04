#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>
template<class T>
struct point {
    T x;
    T y;
};
template<class T>
point<T> operator- (point<T> l, point<T> r) {
    return { r.x - l.x, r.y - l.y};
};
template<class T>
std::istream& operator>> (std::istream& is, point<T>& p) {
    is >> p.x >> p.y;
    return is;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const point<T>& p) {
    os << p.x << ' ' << p.y;
    return os;
}

template<class T>
T VectNorm(point<T> l, point<T> r) {
    point<T> vect = operator-(l, r);
    double res = sqrt(vect.x * vect.x + vect.y * vect.y);
    return res;
}

template<class T>
T ScalProd(point<T> l, point<T> r) {
    return std::abs(l.x * r.x + l.y * r.y);
}
template<class T>
T TrAngle(point<T> a, point<T> b, point<T> c) {
    point<T>  v1, v2;
    v1 = operator-(a, b);
    v2 = operator-(a, c);
    return std::abs(v1.x * v2.y - v2.x * v1.y) / 2;
}

template<class T>
T VectProd(point<T> a, point<T> b) {
    return a.x * b.y - b.x * a.y;
}
