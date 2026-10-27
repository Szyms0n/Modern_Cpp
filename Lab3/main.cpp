#include <iostream>
#include <optional>
#include <cmath>
#include "cameraParams.hpp"
#include "point.hpp"
#include "fib.hpp"

std::optional<std::pair<double, double>> solveQuadraticEquation(double a, double b, double c);


int main() {

    int test = fib_for(9);
    std::cout<<test<<std::endl;

    double fibonacci = fib_recurrency(9);
    std::cout<<fibonacci<<std::endl;



    // for (int i=0; i  < argc; i++) {
    //     std::cout<<argv[i]<<std::endl;
    //
    // }
    //
    // const auto t1= solveQuadraticEquation(std::stod(argv[0]), std::stod(argv[1]), std::stod(argv[2]));
    // std::cout<<t1;

    point2D p1{1000,750};
    p1.calculateToMm();

    point2D p2{-300,750};
    p2.calculateToMm();

    cameraParams camera{20, 300, 6000, 4000, 0.005};
    camera.calculateParamsToMm();

    auto result = point2D::calculatePoint3D_2(p1, p2, camera);
    if (result) {
        auto [x,y,z] = result.value();
        const point3D p3{x,y,z};
        p3.printInfo();

        auto[q, p] = point3D::projectPointOnScreen(camera, p3);
        std::cout<<q<<" "<<p<<std::endl;
    }
    else {
        std::cout<<result.error();
    }
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}


    std::optional<std::pair<double, double>> solveQuadraticEquation(double a, double b, double c){

    if (a == 0) {
        if (b == 0 ) {
            return std::nullopt;
        }
        double x = -c/b;
        return std::make_pair(x, x);
    };
    const double delta = b * b - 4 * a * c;
    if (delta < 0) {
        return std::nullopt;
    }
    const double sqrtDelta = std::sqrt(delta);
    double const x1  = (sqrtDelta - b)/2*a;
    double const x2  = (-sqrtDelta + b)/2*a;
    return std::make_pair(x1, x2);
    };