#pragma once
#include <tuple>
#include "cameraParams.hpp"
#include <expected>
#include <iostream>

struct point3D {
    double x{0};
    double y{0};
    double z{0};

    void printInfo() const;
    static std::tuple<double, double> projectPointOnScreen(const cameraParams& camera, const point3D& point);
};

struct point2D {
    double x{0};
    double y{0};

    void calculateToMm();
    static std::tuple<double, double, double> calculatePoint3D( const point2D& point1, const point2D& point2,  const cameraParams& camera );
    static std::expected<point3D, std::string> calculatePoint3D_2(const point2D& point1, const point2D& point2,  const cameraParams& camera);


};