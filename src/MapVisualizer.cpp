#include "include/MapVisualizer.h"

void MapVisualizer::update() {
    try {
        displayRealTimeMap();
    } catch (const std::exception &e) {
        std::cerr << "Error updating map: " << e.what() << std::endl;
    }
}

void MapVisualizer::display3dPoint() {
    try {
        if (!point_cloud) {
            throw std::runtime_error("Point cloud is not initialized.");
        }

        open3d::visualization::Visualizer visualizer;
        visualizer.CreateVisualizerWindow("Real-Time Point Cloud Map", 1280, 720);
        visualizer.AddGeometry(point_cloud);

        open3d::visualization::RenderOption &ro = visualizer.GetRenderOption();
        ro.point_size_ = 1.0;

        while (!visualizer.WasStopped()) {
            visualizer.UpdateGeometry();
            visualizer.PollEvents();
            visualizer.UpdateRender();
        }
    } catch (const std::exception &e) {
        std::cerr << "Error displaying 3D point cloud: " << e.what() << std::endl;
    }
}

void MapVisualizer::display2dPoint() {
    try {
        if (!point_cloud) {
            throw std::runtime_error("Point cloud is not initialized.");
        }

        open3d::visualization::Visualizer visualizer;
        visualizer.CreateVisualizerWindow("Real-Time Point Cloud Map", 1280, 720);

        open3d::geometry::PointCloud projected_point_cloud;
        projected_point_cloud.points_ = point_cloud.points_;
        for (auto &point : projected_point_cloud.points_) {
            point[2] = 0.0;
        }

        visualizer.AddGeometry(projected_point_cloud);

        open3d::visualization::RenderOption &ro = visualizer.GetRenderOption();
        ro.point_size_ = 1.0;

        while (!visualizer.WasStopped()) {
            visualizer.UpdateGeometry();
            visualizer.PollEvents();
            visualizer.UpdateRender();
        }
    } catch (const std::exception &e) {
        std::cerr << "Error displaying 2D point cloud: " << e.what() << std::endl;
    }
}

void MapVisualizer::switchMap(int type) {
    try {
        if (type != TWO_D_MAP && type != THREE_D_MAP) {
            throw std::invalid_argument("Invalid map type. Cannot switch map.");
        }

        if (type == TWO_D_MAP) {
            display2dPoint();
        } else if (type == THREE_D_MAP) {
            display3dPoint();
        }
    } catch (const std::exception &e) {
        std::cerr << "Error switching map: " << e.what() << std::endl;
    }
}

open3d::geometry::PointCloud visualizeRobotPose() {
    try {
        open3d::geometry::PointCloud pointCloud;

        Eigen::Vector3d robotPose(0.0, 0.0, 0.0);
        pointCloud.points_.push_back(robotPose);

        return pointCloud;
    } catch (const std::exception &e) {
        std::cerr << "Error visualizing robot pose: " << e.what() << std::endl;
        return open3d::geometry::PointCloud();  // Return an empty point cloud on error
    }
}
