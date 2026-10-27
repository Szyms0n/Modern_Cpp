#pragma once


struct cameraParams {
    double f{0}; //mm
    double B{0}; //mm
    double imageWidth{0}; //px
    double imageHeight{0}; //px
    double pixelSize{0}; //mm

    void calculateParamsToMm ();
};


// using D2 = point2D;
// using D3 = point3D;