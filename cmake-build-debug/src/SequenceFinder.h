//
// Created by laura on 7/05/25.
//

#ifndef SEQUENCEFINDER_H
#define SEQUENCEFINDER_H
#include <thread>
#include <vector>

#include "IModule.h"


class SequenceFinder : public IModule{
    std::jthread thread;
    std::atomic<bool> isRunning;
    IModule *nextModule = nullptr;
    std::vector<uint8_t> buffer;
public:
    void start() override;
    void stop() override;
    void setNextModule(IModule *next);

private:
    void alive();
    void receivedData(const std::vector<uint8_t> &data);
};



#endif //SEQUENCEFINDER_H
