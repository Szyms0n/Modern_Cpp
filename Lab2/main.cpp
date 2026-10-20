#include <iostream>
#include <expected>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
#include "cameraParams.hpp"
#include "point.hpp"




int main() {

//


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