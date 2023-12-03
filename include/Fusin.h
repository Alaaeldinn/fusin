#ifndef FUSIONX_H
#define FUSIONX_H

#include "SensorFusion.h"

// Concrete implementation for a specific fusion strategy (FusionX)
class FusionX : public SensorFusion {
public:
    void integrateSensorData(const std::vector<double>& data) override;
    void extractFeatures(const std::vector<double>& sensorData) override;
    void matchFeatures(const std::vector<double>& features) override;
    void applyFilter(const std::vector<double>& fusedData) override;
    void handleOutliers(const std::vector<double>& data) override;
};

#endif // FUSIONX_H
