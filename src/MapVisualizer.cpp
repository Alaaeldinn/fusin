#include "include/MapVisualizer.h"
#include <iostream>

void MapVisualizer::update() {
    displayRealTimeMap();
}

void MapVisualizer::displayRealTimeMap() {
    std::cout << "Displaying real-time map..." << std::endl;
}

void MapVisualizer::switchMap(int type) {
    std::cout << "Switching to map type: " << type << std::endl;
}

void MapVisualizer::visualizeRobotPose(double pose, double uncertainty) {
    std::cout << "Visualizing robot pose: " << pose << " with uncertainty: " << uncertainty << std::endl;
}

void MapVisualizer::zoomIn() {
    std::cout << "Zooming in..." << std::endl;
}

void MapVisualizer::zoomOut() {
    std::cout << "Zooming out..." << std::endl;
}