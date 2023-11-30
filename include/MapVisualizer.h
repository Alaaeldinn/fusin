#include "MapSubject.h"

class MapVisualizer : public MapObserver {
public:
    void update() override;
    void displayRealTimeMap();
    void switchMap(int type);
    void visualizeRobotPose(double pose, double uncertainty);
    void zoomIn();
    void zoomOut();
};