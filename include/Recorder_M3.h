//
// Created by laura on 9/05/25.
//

#ifndef BYTESRECORDER_H
#define BYTESRECORDER_H
#include <condition_variable>
#include <list>
#include <thread>
#include <vector>
#include "IModule.h"


class Recorder_M3 : public IModule {
public:
    void start(IModule *next) override;
    void stop() override;
    void receiveData(std::vector<uint8_t>& data) override;
private:
    std::jthread thread;
    std::atomic<bool> isRunning;
    IModule* nextModule = nullptr;
    std::list<std::pair<std::chrono::system_clock::time_point, std::vector<uint8_t>>> records;
    std::mutex mtx;
    std::condition_variable cv;
    void printer();
    void process();
};



#endif //BYTESRECORDER_H
