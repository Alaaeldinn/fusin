#include "MapSubject.h"
#include <Thirdparty/Open3D/Open3D.h>
class MapVisualizer : public MapObserver {
public:
    void update() override;
    void display3dPoint(const open3d::geometry::PointCloud &point_cloud);
    void display2dPoint(const open3d::geometry::PointCloud &point_cloud);
    void switchMap(int type);
    open3d::geometry::PointCloud visualizeRobotPose();
    void zoomIn();
    void zoomOut();
};
