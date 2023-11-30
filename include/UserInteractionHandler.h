#ifndef USER_INTERACTION_HANDLER_H
#define USER_INTERACTION_HANDLER_H

#include <vector>

class RealTimeFeedbackHandler;

class UserInteractionHandler {
public:
    UserInteractionHandler(RealTimeFeedbackHandler* feedbackHandler);
    void enableManualControl();
    void setWaypoints(const std::vector<std::string>& goals);
    void facilitateSensorCalibration();
    void teleoperateRobot();

private:
    class UserInteractionState;
    class ManualControlState;
    class WaypointsState;
    class SensorCalibrationState;
    class TeleoperationState;

    UserInteractionState* currentState;
    RealTimeFeedbackHandler* feedbackHandler;
};

#endif // USER_INTERACTION_HANDLER_H
