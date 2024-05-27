#ifndef MAINPROJECT_OBSERVER_H
#define MAINPROJECT_OBSERVER_H

#include <vector>

/**
 * @brief Interface for observers that wish to be notified of changes.
 */
class Observer {
public:
    /**
     * @brief Virtual method called when an update occurs.
     */
    virtual void update() = 0;

    /**
     * @brief Virtual destructor for Observer class.
     */
    virtual ~Observer() {}
};

/**
 * @brief Subject class that observes changes and notifies observers.
 */
class Subject {
private:
    std::vector<Observer*> observers; /**< Vector to store observers. */

public:
    /**
     * @brief Attaches an observer to the subject.
     * @param observer The observer to attach.
     */
    void attach(Observer* observer);

    /**
     * @brief Detaches an observer from the subject.
     * @param observer The observer to detach.
     */
    void detach(Observer* observer);

    /**
     * @brief Notifies all observers of changes.
     */
    void notify();
};

#endif // MAINPROJECT_OBSERVER_H
