#include <iostream>
#include "pentagon.h"
#include "trapeze.h"
#include "templates.h"
#include "rhombus.h"
void help () {
    std::cout << "1 - pentagon\n"
                 "2 - rhombus\n"
                 "3 - trapeze\n"
                 "4 - exit\n";
}

int main() {
    int choice;
    point<double> v1,v2,v3,v4,v5;
    help();
    std::cin >> choice;
    while (choice != 4) {
        if (choice == 1) {
            pentagon<double> p(std::cin);
            std::cout << "area: " << area(p) << '\n' << "center: " << center(p) << '\n';
            print(p, std::cout);
            std::cout << "Enter a pentagonal tuple\n";
            std::cin >> v1 >> v2 >> v3 >> v4 >> v5;
            std::tuple<point<double>, point<double>, point<double>, point<double>, point<double>> p1{v1, v2, v3, v4,v5};
            std::cout << "area: " << area(p1) << '\n' << "center: " << center(p1) << '\n';
            print(p1, std::cout);
        } else if (choice == 2) {
            trapeze<double> h(std::cin);
            std::cout << "area: " << area(h) << '\n' << "center: " << center(h) << '\n';
            print(h, std::cout);
            std::cout << "Enter a trapezoidal tuple\n";
            std::cin >> v1 >> v2 >> v3 >> v4;
            std::tuple<point<double>, point<double>, point<double>, point<double>> h1{v1, v2, v3, v4};
            std::cout << "area: " << area(h1) << '\n' << "center: " << center(h1) << '\n';
            print(h1, std::cout);
        } else if (choice == 3) {
            rhombus<double> o(std::cin);
            std::cout << "area: " << area(o) << '\n' << "center: " << center(o) << '\n';
            print(o, std::cout);
            std::cout << "Enter a rhombus tuple\n";
            std::cin >> v1 >> v2 >> v3 >> v4;
            std::tuple<point<double>, point<double>, point<double>,  point<double>> o1{v1, v2, v3, v4};
            std::cout << "area: " << area(o1) << '\n' << "center: " << center(o1) << '\n';
            print(o1, std::cout);
        } else {
            std::cout << "The command is uncertain\n";
        }
        std::cin >> choice;
    }
    return 0;
}