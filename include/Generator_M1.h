//
// Created by laura on 7/05/25.
//

#ifndef BYTESGENERATOR_H
#define BYTESGENERATOR_H
#include <thread>
#include <vector>
#include "IModule.h"


class Generator_M1 : public IModule{
public:
    Generator_M1() = default;
    ~Generator_M1() override = default;
    void start(IModule* next) override;
    void stop() override;
    void receiveData(std::vector<uint8_t> &data) override{};
private:
    std::jthread thread;
    std::atomic<bool> isRunning;
    IModule* nextModule = nullptr;

    void run(IModule* next);
};



#endif //BYTESGENERATOR_H
