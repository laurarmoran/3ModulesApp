//
// Created by laura on 7/05/25.
//

#ifndef SEQUENCEFINDER_H
#define SEQUENCEFINDER_H
#include <condition_variable>
#include <list>
#include <thread>
#include <vector>
#include "IModule.h"


class SequenceFinder : public IModule{
public:
    SequenceFinder() = default;
    ~SequenceFinder() override = default;
    void start(IModule *next) override;
    void stop() override;
    void receiveData(std::vector<uint8_t> &data) override;

private:
    std::jthread thread;
    std::atomic<bool> isRunning;
    IModule* nextModule = nullptr;
    std::list<std::vector<uint8_t>> buffer;
    std::mutex mtx;
    std::condition_variable cv;
    std::vector<uint8_t> byteMatch{0x00, 0x01, 0x02};
    void finder(IModule *next);
};



#endif //SEQUENCEFINDER_H
