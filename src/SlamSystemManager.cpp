// SLAMSystemManager.cpp
#include "include/SlamSystemManager.h"
#include <iostream>

void SlamSystemManager::integrateSLAMData(const std::string& fusedData) {
    for (auto algorithm : algorithms) {
        algorithm->integrateSLAMData(fusedData);
    }
}

void SlamSystemManager::detectLoopClosure() {
    for (auto algorithm : algorithms) {
        algorithm->detectLoopClosure();
    }
}

void SlamSystemManager::handleDynamicObjects() {
    for (auto algorithm : algorithms) {
        algorithm->handleDynamicObjects();
    }
}

void SlamSystemManager::addSLAMAlgorithm(SLAMAlgorithm* algorithm) {
    algorithms.push_back(algorithm);
}

void SlamSystemManager::removeSLAMAlgorithm(SLAMAlgorithm* algorithm) {
    algorithms.erase(std::remove(algorithms.begin(), algorithms.end(), algorithm), algorithms.end());
}

SlamSystemManager::~SlamSystemManager() {
    for (auto algorithm : algorithms) {
        delete algorithm;
    }
}
