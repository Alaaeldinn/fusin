#include "include/MapSubject.h"

void MapSubject::addObserver(MapObserver* observer) {
    observers.push_back(observer);
}

void MapSubject::notifyObservers() {
    for (MapObserver* observer : observers) {
        observer->update();
    }
}