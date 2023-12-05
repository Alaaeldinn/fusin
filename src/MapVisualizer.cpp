#include "include/MapVisualizer.h"

void MapVisualizer::update() {
    displayRealTimeMap();
}

void MapVisualizer::display3dPoint() {
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

void MapVisualizer::display2dPoint() {
    // Create a visualization window
    open3d::visualization::Visualizer visualizer;
    visualizer.CreateVisualizerWindow("Real-Time Point Cloud Map", 1280, 720);

    // Project the 3D point cloud onto the XY plane (set z component to zero)
    open3d::geometry::PointCloud projected_point_cloud;
    projected_point_cloud.points_ = point_cloud.points_;
    for (auto &point : projected_point_cloud.points_) {
        point[2] = 0.0;
    }

    // Add the 2D point cloud to the visualizer
    visualizer.AddGeometry(projected_point_cloud);

    // Set up the rendering options (optional)
    open3d::visualization::RenderOption &ro = visualizer.GetRenderOption();
    ro.point_size_ = 1.0;

    // Run the visualization loop
    while (!visualizer.WasStopped()) {
        visualizer.UpdateGeometry();
        visualizer.PollEvents();
        visualizer.UpdateRender();
    }
}

void MapVisualizer::switchMap(int type) {
    if (type == 2) {
        display2dPoint();
    } else if (type == 3) {
        display3dPoint();
    } else {
        // Handle invalid type
        std::cerr << "Invalid type. Cannot switch map." << std::endl;
    }
}

    
open3d::geometry::PointCloud visualizeRobotPose() {
        // Create a point cloud
        open3d::geometry::PointCloud pointCloud;

        // Set robot pose (replace these values with your actual robot pose)
        Eigen::Vector3d robotPose(0.0, 0.0, 0.0);

        // Add a single point to represent the robot pose
        pointCloud.points_.push_back(robotPose);

        // Return the created point cloud
        return pointCloud;
}


void MapVisualizer::zoomIn() {
    std::cout << "Zooming in..." << std::endl;
}

void MapVisualizer::zoomOut() {
    std::cout << "Zooming out..." << std::endl;
}
