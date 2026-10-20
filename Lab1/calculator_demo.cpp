#include <iostream>
// Created by Szymon Hetman on 19/10/2026.
//
#include <iostream>
#include "calc.hpp"
// using namespace calculator; optional
int main() {
    std::cout<< calculator::sum(3.5, 1.5)<< std::endl;
    std::cout<< calculator::multiply(2, 3)<< std::endl;
    return EXIT_SUCCESS;
}