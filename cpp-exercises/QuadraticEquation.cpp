#include <tuple>
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>

std::pair<double, double> findRoots(double a, double b, double c)
{
    double discriminant = std::pow(b,2) - 4*a*c;
        
    std::pair<double, double> roots;
    
    roots.first = (-b + std::sqrt(discriminant))/(2*a);
    roots.second = (-b - std::sqrt(discriminant))/(2*a);
     
    return roots;
    
        
}

#ifndef RunTests
int main()
{
    std::pair<double,double> roots = findRoots(2, 10, 8);
    std::cout << "Roots: " + std::to_string(roots.first) + ", " + std::to_string(roots.second);
}
#endif