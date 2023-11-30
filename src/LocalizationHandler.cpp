// LocalizationHandler.cpp
#include "include/LocalizationHandler.h"

LocalizationHandler::LocalizationHandler(SensorFusion* fusion, RealTimeFeedbackHandler* feedback)
    : sensorFusion(fusion), feedbackHandler(feedback) {}

void LocalizationHandler::implementLocalizationAlgorithms() {
    // Assuming sensor fusion and feedback handler are used in the implementation
    sensorFusion->performFusion();  // Example: Call a method on SensorFusion
    feedbackHandler->handleRealTimeFeedback();  // Example: Call a method on RealTimeFeedbackHandler

    // Implementation of localization algorithms
    // ...

    // Notify observers about changes
    for (auto observer : observers) {
        observer->update();
    }
}

void LocalizationHandler::updateRobotPose(const std::string& fusedData) {
    // Assuming sensor fusion and feedback handler are used in the implementation
    sensorFusion->processFusedData(fusedData);  // Example: Call a method on SensorFusion

    // Update robot pose based on fused sensor data
    // ...

    // Notify observers about changes
    for (auto observer : observers) {
        observer->update();
    }
}

void LocalizationHandler::adaptToEnvironmentChanges() {
    // Assuming sensor fusion and feedback handler are used in the implementation
    feedbackHandler->adaptToChanges();  // Example: Call a method on RealTimeFeedbackHandler

    // Adapt to environmental changes
    // ...

    // Notify observers about changes
    for (auto observer : observers) {
        observer->update();
    }
}

void LocalizationHandler::fuseMultiModalSensors() {
    // Assuming sensor fusion and feedback handler are used in the implementation
    sensorFusion->fuseMultiModalSensors();  // Example: Call a method on SensorFusion

    // Fusion of multi-modal sensors
    // ...

    // Notify observers about changes
    for (auto observer : observers) {
        observer->update();
    }
}

void LocalizationHandler::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void LocalizationHandler::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

LocalizationHandler::~LocalizationHandler() {
    // No need to delete dependencies here as they are not owned by LocalizationHandler
}
