#include "include/WaypointsState.h"

void UserInteractionHandler::WaypointsState::handleState(UserInteractionHandler* context) {
    // Logic for handling WaypointsState
    for (const auto& waypoint : context->getWaypoints()) {
        // Perform sensor fusion logic for each waypoint
        // Example: context->performSensorFusion(waypoint);
    }
}
