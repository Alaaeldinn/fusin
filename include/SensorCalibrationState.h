#ifndef SENSOR_CALIBRATION_STATE_H
#define SENSOR_CALIBRATION_STATE_H

#include "include/UserInteractionHandler.h"

class UserInteractionHandler::SensorCalibrationState : public UserInteractionHandler::UserInteractionState {
public:
    void handleState(UserInteractionHandler* context) override;
};

#endif // SENSOR_CALIBRATION_STATE_H
