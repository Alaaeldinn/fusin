#ifndef WAYPOINTS_STATE_H
#define WAYPOINTS_STATE_H

#include "include/UserInteractionHandler.h"

class UserInteractionHandler::WaypointsState : public UserInteractionHandler::UserInteractionState {
public:
    void handleState(UserInteractionHandler* context) override;
};

#endif // WAYPOINTS_STATE_H
