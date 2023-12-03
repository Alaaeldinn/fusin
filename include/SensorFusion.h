#ifndef SENSORFUSION_H
#define SENSORFUSION_H
#include <iostream>
#include <vector>

class SensorFusion {
public:
    virtual ~SensorFusion() = default;
    virtual void integrateSensorData(const std::vector<double>& data) = 0;
    virtual void extractFeatures(const std::vector<double>& sensorData) = 0;
    virtual void matchFeatures(const std::vector<double>& features) = 0;
    virtual void applyFilter(const std::vector<double>& fusedData) = 0;
    virtual void handleOutliers(const std::vector<double>& data) = 0;
};

#endif // SENSORFUSION_H
