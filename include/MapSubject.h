#include <vector>
#include "MapObserver.h"

class MapSubject {
private:
    std::vector<MapObserver*> observers;

public:
    void addObserver(MapObserver* observer);
    void notifyObservers();
};