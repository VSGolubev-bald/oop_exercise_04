#include "point.h"
#pragma once
template<class T>
struct rhombus {
private:
    point<T> a1,a2,a3,a4;
public:
    point<T> center() const;
    void print(std::ostream& os) const;
    double area() const;
    rhombus(std::istream& is);
};
template<class T>
rhombus<T>::rhombus(std::istream &is) {
    is >> a1 >> a2 >> a3 >> a4;
    if ( VectProd(operator-(a1, a2), operator-(a4, a3)) == 0  &&
         VectProd(operator-(a1, a4), operator-(a2, a3)) == 0 &&
         ScalProd(operator-(a3, a1), operator-(a4, a2)) == 0 ) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Wrong" << std::endl;
        throw 1;
    }
}
template<class T>
double rhombus<T>::area() const {
    return VectNorm(a3, a1) * VectNorm(a4, a2) / 2;
}

template<class T>
point<T> rhombus<T>::center() const {
    return point<T> {((a1.x + a2.x + a3.x + a4.x) / 4), ((a1.y + a2.y + a3.y + a4.y) / 4)};
}

template<class T>
void rhombus<T>::print(std::ostream &os) const {
    os << a1 << "\n"<< a2 << "\n" << a3 << "\n" << a4 << "\n";
}
