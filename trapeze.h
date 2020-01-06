#pragma once

#include "point.h"

template<class T>
struct trapeze {
private:
    point<T> a1,a2,a3,a4;
public:
    point<T> center() const;
    void print(std::ostream& os) const;
    double area() const;
    trapeze(std::istream& is);
};

template<class T>
point<T> trapeze<T>::center() const {
    T x,y;
    x = (a1.x + a2.x + a3.x + a4.x ) / 4;
    y = (a1.y + a2.y + a3.y + a4.y ) / 4;
    return {x,y};
}

template<class T>
trapeze<T>::trapeze(std::istream &is) {
    is >> a1 >> a2 >> a3 >> a4;
    if ( ( VectProd(operator-(a1,a2), operator-(a4,a3)) == 0) ||
         (VectProd(operator-(a2,a3), operator-(a1,a4)) == 0) ) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Wrong" << std::endl;
        throw 1;
    }
}

template<class T>
void trapeze<T>::print(std::ostream& os) const {
    os << a1 << "\n"<< a2 << "\n" << a3 << "\n" << a4 << "\n";
}

template<class T>
double trapeze<T>::area() const {
    if ( (VectProd(operator-(a1,a2), operator-(a3,a4)) == 0) && (VectProd(operator-(a2,a3), operator-(a1,a4)) == 0) ) {
        return fabs((VectProd(operator-(a1,a2), operator-(a1,a4)))) ;
    } else if (VectProd(operator-(a1,a2), operator-(a4,a3)) == 0) {
        return ((VectNorm(a1, a2) + VectNorm(a4, a3)) / 2) * sqrt(
                VectNorm(a4, a1) * VectNorm(a4, a1) - (
                        pow((
                                    (pow((VectNorm(a4, a3) - VectNorm(a1, a2)), 2) +
                                     VectNorm(a4, a1) * VectNorm(a4, a1) - VectNorm(a2, a3) * VectNorm(a2, a3)) /
                                    (2 * (VectNorm(a4, a3) - VectNorm(a1, a2)))
                            ), 2)
                )
        );

    } else if (VectProd(operator-(a2,a3), operator-(a1,a4)) == 0) {
        return ((VectNorm(a2, a3) + VectNorm(a1, a4)) / 2) * sqrt(
                VectNorm(a1, a2) * VectNorm(a1, a2) - (
                        pow((
                                    (pow((VectNorm(a1, a4) - VectNorm(a2, a3)), 2) +
                                     VectNorm(a1, a2) * VectNorm(a1, a2) - VectNorm(a3, a4) * VectNorm(a3, a4)) /
                                    (2 * (VectNorm(a1, a4) - VectNorm(a2, a3)))
                            ), 2)
                )
        );
    }
}