#include "include/DataManager.h"

// Initialize the static instance of DataManager
DataManager DataManager::instance;

// Define the public function to get the instance of DataManager
DataManager& DataManager::getInstance() {
    return instance;
}

// Define function to record and save sensor data
// DataManager.cpp (Source code file)

pcl::PointCloud<pcl::PointXYZ>::Ptr DataManager::recordSensorData(const std::vector<MyPoint>& customPointCloud)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr pclPointCloud(new pcl::PointCloud<pcl::PointXYZ>);

    pclPointCloud->reserve(customPointCloud.size()); // Reserve space for all points at once

    for (const auto& point : customPointCloud)
    {
        pclPointCloud->emplace_back(point.x, point.y, point.z);
    }

    // Further processing or storage as needed.

    return pclPointCloud;
}

void DataManager::SaveData(const std::vector<MyPoint>& customPointCloud) {
    // Record sensor data and obtain point cloud
    pcl::PointCloud<pcl::PointXYZ>::Ptr pclPointCloud = recordSensorData(customPointCloud);

    // Save point cloud data to a PCD file
    pcl::io::savePCDFileASCII("sensor_data.pcd", *pclPointCloud);
}


