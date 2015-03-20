#ifndef GAMEUPDATER_HPP
#define GAMEUPDATER_HPP

#include <condition_variable>
#include <mutex>
#include <thread>

#include "EventManager.hpp"

class GameUpdater {

public:
    GameUpdater(EventManager&);
    ~GameUpdater();

    void run();
    void update(unsigned long);
    void wait();
    void stop();

private:
    EventManager& eventManager;

    // thread stuff
    bool shouldContinue;
    bool shouldRun;
    bool done;
    std::thread updater;
    std::mutex mutex;
    std::condition_variable conditionVar;

    // thread communicated values
    unsigned long frameLived;

};

#endif
