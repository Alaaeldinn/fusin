#ifndef MANUAL_CONTROL_STATE_H
#define MANUAL_CONTROL_STATE_H

#include "include/UserInteractionHandler.h"

class UserInteractionHandler::ManualControlState : public UserInteractionHandler::UserInteractionState {
public:
    void handleState(UserInteractionHandler* context) override;
};

#endif // MANUAL_CONTROL_STATE_H
