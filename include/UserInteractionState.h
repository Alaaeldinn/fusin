#ifndef USER_INTERACTION_STATE_H
#define USER_INTERACTION_STATE_H

class UserInteractionHandler;

class UserInteractionHandler::UserInteractionState {
public:
    virtual void handleState(UserInteractionHandler* context) = 0;
    virtual ~UserInteractionState() = default;
};

#endif // USER_INTERACTION_STATE_H
