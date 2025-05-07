//
// Created by laura on 7/05/25.
//

#ifndef IMODULE_H
#define IMODULE_H
#include <memory>

#endif //IMODULE_H

class IModule {
public:
    virtual ~IModule();
    virtual void start(){};
    virtual void stop(){};
private:
    class PImpl;
    std::unique_ptr<PImpl> pimpl;
};

/*class pImpl{
public:
    virtual ~pImpl() = default;
    virtual void start(){};
    virtual void stop(){};
    virtual void set(){};
};*/