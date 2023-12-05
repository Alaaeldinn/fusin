#include "MapSubject.h"
#include <Thirdparty/Open3D/Open3D.h>

class MapVisualizer : public MapObserver {

private:
    open3d::geometry::PointCloud point_cloud;
public:
    void update() override;
    void display3dPoint();
    void display2dPoint();
    void switchMap(int type);
    open3d::geometry::PointCloud visualizeRobotPose();
    void zoomIn();
    void zoomOut();
};
