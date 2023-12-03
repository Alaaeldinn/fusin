// DataManager.h (Header file for your source code)
#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "thirdparty/pcl/point_cloud.h"
#include "thirdparty/pcl/io/pcd_io.h"
#include "thirdparty/pcl/point_types.h"

struct MyPoint
{
    float x, y, z;
    // Add other fields if necessary
};

class DataManager {
public:
    // Function to get the instance of DataManager
    static DataManager& getInstance();

    // Function to record and save sensor data
    pcl::PointCloud<pcl::PointXYZ>::Ptr recordSensorData(const std::vector<MyPoint>& customPointCloud);

    // Function to manage export of maps and pose data
    void exportData(const std::map<std::string, std::string>& mapData, const std::string& poseData);


private:
    // Private constructor to prevent instantiation
    DataManager();

    // Private copy constructor and assignment operator to prevent duplication
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;

    // Private static instance of DataManager
    static DataManager instance;
};

#endif
