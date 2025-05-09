//
// Created by laura on 7/05/25.
//

#ifndef IMODULE_H
#define IMODULE_H

#include <vector>

class IModule {
public:
    virtual ~IModule() = default;
    virtual void start(IModule* next){};
    virtual void stop(){};
    virtual void receiveData(std::vector<uint8_t> &data){};
};
#endif //IMODULE_H