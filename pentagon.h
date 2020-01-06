#include "point.h"
#pragma once
template<class T>
struct pentagon{
private:
    point<T> a1,a2,a3,a4,a5;
public:
    point<T> center() const;
    void print(std::ostream& os) const;
    double area() const;
    pentagon(std::istream& is);
};
template<class T>
pentagon<T>::pentagon(std::istream &is) {
    is >> a1 >> a2 >> a3 >> a4 >> a5;
}
template<class T>
point<T> pentagon<T>::center() const {
    return point<T> {((a1.x + a2.x + a3.x + a4.x + a5.x) / 5), ((a1.y + a2.y + a3.y + a4.y + a5.y) / 5) } ;
}
template<class T>
double pentagon<T>::area() const {
    return TrAngle(a1,a2,a3) + TrAngle(a3,a4,a5) + TrAngle(a1,a3,a5);
}

template<class T>
void pentagon<T>::print(std::ostream& os) const {
    os << "coordinate:\n" << a1 << '\n' << a2 << '\n' << a3 << '\n' << a4 << '\n' << a5 << '\n';
}
