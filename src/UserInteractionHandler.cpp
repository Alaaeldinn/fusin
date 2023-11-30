#include "include/UserInteractionHandler.h"
#include "include/RealTimeFeedbackHandler.h"
#include "include/ManualControlState.h"
#include "include/WaypointsState.h"
#include "include/SensorCalibrationState.h"
#include "include/TeleoperationState.h"

UserInteractionHandler::UserInteractionHandler(RealTimeFeedbackHandler* feedbackHandler)
    : currentState(nullptr), feedbackHandler(feedbackHandler) {
    currentState = new ManualControlState();
}

void UserInteractionHandler::enableManualControl() {
    currentState->handleState(this);
}

void UserInteractionHandler::setWaypoints(const std::vector<std::string>& goals) {
    currentState->handleState(this);
    // Additional logic for handling waypoints state
}

void UserInteractionHandler::facilitateSensorCalibration() {
    currentState->handleState(this);
    // Additional logic for handling sensor calibration state
}

void UserInteractionHandler::teleoperateRobot() {
    currentState->handleState(this);
    // Additional logic for handling teleoperation state
}
