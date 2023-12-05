#include "MapSubject.h"
#include <Thirdparty/Open3D/Open3D.h>

#define TWO_D_MAP 2
#define THREE_D_MAP 3

class MapVisualizer : public MapObserver {

private:
    open3d::geometry::PointCloud point_cloud;
public:
    void update() override;
    void display3dPoint();
    void display2dPoint();
    void switchMap(int type);
    open3d::geometry::PointCloud visualizeRobotPose();
};
