#include "observer.h"

void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer* observer) {

    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}


void Subject::notify() {

    for (Observer* observer : observers) {
        observer->update();
    }
}