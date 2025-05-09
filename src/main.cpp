#include <memory>
#include <thread>

#include "../include/IModule.h"
#include "../include/Generator_M1.h"
#include "../include/SequenceFinder.h"
#include "../include/Recorder_M3.h"


class IModule;

int main() {
    std::unique_ptr<IModule> m1 = std::make_unique<Generator_M1>();
    std::unique_ptr<IModule> m2 = std::make_unique<SequenceFinder>();
    std::unique_ptr<IModule> m3 = std::make_unique<Recorder_M3>();

    m1->start(m2.get());
    m2->start(m3.get());
    m3->start(nullptr);

    std::this_thread::sleep_for(std::chrono::seconds(15));

    m1->stop();
    m2->stop();
    m3->stop();

    return 0;
}
