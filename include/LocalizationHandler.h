// LocalizationHandler.h
#ifndef LOCALIZATIONHANDLER_H
#define LOCALIZATIONHANDLER_H

#include <vector>
#include <iostream>

// Forward declaration of dependencies
class SensorFusion;
class RealTimeFeedbackHandler;

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() {}
};

class LocalizationHandler {
private:
    std::vector<Observer*> observers;

    // Dependencies
    SensorFusion* sensorFusion;
    RealTimeFeedbackHandler* feedbackHandler;

public:
    LocalizationHandler(SensorFusion* fusion, RealTimeFeedbackHandler* feedback);
    void implementLocalizationAlgorithms();
    void updateRobotPose(const std::string& fusedData);
    void adaptToEnvironmentChanges();
    void fuseMultiModalSensors();

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    ~LocalizationHandler();
};

#endif // LOCALIZATIONHANDLER_H
