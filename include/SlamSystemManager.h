// SLAMSystemManager.h
#ifndef SLAMSYSTEMMANAGER_H
#define SLAMSYSTEMMANAGER_H

#include <vector>

class SLAMAlgorithm {
public:
    virtual void integrateSLAMData(const std::string& fusedData) = 0;
    virtual void detectLoopClosure() = 0;
    virtual void handleDynamicObjects() = 0;
    virtual ~SLAMAlgorithm() {}
};

class SlamSystemManager : public SLAMAlgorithm {
private:
    std::vector<SLAMAlgorithm*> algorithms;

public:
    void integrateSLAMData(const std::string& fusedData) override;
    void detectLoopClosure() override;
    void handleDynamicObjects() override;

    void addSLAMAlgorithm(SLAMAlgorithm* algorithm);
    void removeSLAMAlgorithm(SLAMAlgorithm* algorithm);
    ~SLAMSystemManager();
};

#endif // SLAMSYSTEMMANAGER_H
