#include "include/MapVisualizer.h"

void MapVisualizer::update() {
    displayRealTimeMap();
}

void MapVisualizer::displayRealTimeMap(const open3d::geometry::PointCloud &point_cloud) {
    open3d::visualization::Visualizer visualizer;
    visualizer.CreateVisualizerWindow("Real-Time Point Cloud Map", 1280, 720);
    // Add the point cloud to the visualizer
    visualizer.AddGeometry(point_cloud);
    // Set up the rendering options (optional)
    open3d::visualization::RenderOption &ro = visualizer.GetRenderOption();
    ro.point_size_ = 1.0;

    // Run the visualization loop
    // main while loop
    while (!visualizer.WasStopped()) {
        visualizer.UpdateGeometry();
        visualizer.PollEvents();
        visualizer.UpdateRender();
    }
}

void MapVisualizer::switchMap(int type) {
    if (type == 2) {
        // Switch to 2D point cloud visualization
        std::cout << "Switching to 2D point cloud visualization..." << std::endl;
        // Implement the 2D visualization logic here
    } else if (type == 3) {
        // Switch to 3D point cloud visualization
        std::cout << "Switching to 3D point cloud visualization..." << std::endl;
        // Implement the 3D visualization logic here
    } else {
        // Handle invalid type
        std::cerr << "Invalid type. Cannot switch map." << std::endl;
    }
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
