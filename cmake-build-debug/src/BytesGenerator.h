//
// Created by laura on 7/05/25.
//

#ifndef BYTESGENERATOR_H
#define BYTESGENERATOR_H
#include <thread>

#include "IModule.h"


class BytesGenerator : public IModule{
    std::jthread thread;
    std::atomic<bool> isRunning;
    IModule *nextModule = nullptr;
public:
    void start() override;
    void stop() override;
    void setNextModule(IModule *next);
private:
    void run() const;
};



#endif //BYTESGENERATOR_H
