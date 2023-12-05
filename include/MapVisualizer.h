#include "MapSubject.h"
#include <Thirdparty/Open3D/Open3D.h>
class MapVisualizer : public MapObserver {
public:
    void update() override;
    void displayRealTimeMap(const open3d::geometry::PointCloud &point_cloud);
    void switchMap(int type);
    void visualizeRobotPose(double pose, double uncertainty);
    void zoomIn();
    void zoomOut();
};
