#include "GameUpdater.hpp"

GameUpdater::GameUpdater(EventManager& manager)
        : eventManager(manager),
          shouldContinue(true),
          shouldRun(false),
          done(false),
          updater(&GameUpdater::run, this) {
}

GameUpdater::~GameUpdater() {
    if(this->shouldContinue) {
        this->stop();
    }
}

void GameUpdater::run() {
    while(shouldContinue) {
        std::unique_lock<std::mutex> lock(this->mutex);
        while(!this->shouldRun) {
            this->conditionVar.wait(lock);
        }

        this->shouldRun = false;
        this->eventManager.tick(frameLived);
        this->eventManager.update();
        this->done = true;

        lock.unlock();
        this->conditionVar.notify_one();
    }
}

void GameUpdater::wait() {
    std::unique_lock<std::mutex> lock(this->mutex);
    while(!this->done) {
        this->conditionVar.wait(lock);
    }
}

void GameUpdater::update(unsigned long frameLived) {
    this->shouldRun = true;
    this->done = false;
    this->frameLived = frameLived;
    this->conditionVar.notify_one();
}

void GameUpdater::stop() {
    this->shouldContinue = false;
    this->shouldRun = true;
    this->conditionVar.notify_one();
    this->updater.join();
}
