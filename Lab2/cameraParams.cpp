
#include "cameraParams.hpp"

void cameraParams::calculateParamsToMm () {
    imageHeight = imageHeight * pixelSize;
    imageWidth = imageWidth * pixelSize;
}

