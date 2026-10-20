//
// Created by Szymon Hetman on 19/10/2026.
//
#include "point.hpp"


std::tuple<double, double, double> point2D::calculatePoint3D( const point2D& point1, const point2D& point2,  const cameraParams& camera) {
    double Zp = (camera.B/ (point1.x - point2.x))*camera.f;
    double Xp = (camera.B/ (point1.x - point2.x))*point1.x;
    double Yp = (camera.B/ (point1.x - point2.x))*point1.y;

    return std::make_tuple(Xp, Yp, Zp);
}

 void point3D::printInfo() const {
    std::cout<<x<<" "<<y<<" "<<z<<std::endl;

}

std::expected<point3D, std::string> point2D::calculatePoint3D_2(const point2D& point1, const point2D& point2,  const cameraParams& camera) {
    if (point1.x < point2.x) {
        return std::unexpected("The point is behind the camera");
    }
    if (point1.x == point2.x) {
        return std::unexpected("division by zero");
    }
    if (point1.y != point2.y) {
        return std::unexpected("Rays don't intersect");
    }
        double distance = point1.x - point2.x;
        double Zp = (camera.B/ distance)*camera.f;
        double Xp = (camera.B/ distance)*point1.x;
        double Yp = (camera.B/ distance)*point1.y;

        return point3D(Xp, Yp, Zp);


};





void point2D::calculateToMm() {
    x=x*0.005;
    y=y*0.005;
}

std::tuple<double, double> point3D::projectPointOnScreen( const cameraParams& camera, const point3D& point) {
    auto xPrime = (point.x/point.z) * camera.f;
    auto yPrime = (point.y/point.z) * camera.f;

    return std::make_tuple(xPrime, yPrime);
}


