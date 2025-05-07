//
// Created by laura on 7/05/25.
//

#include <thread>
#include <vector>
#include <bits/random.h>

#include "IModule.h"

class BytesGen : public IModule {
    std::jthread thread;
    std::atomic<bool> isRunning;
public:
    void start() override {
        isRunning = true;
        thread = std::jthread([this](){run();});
    };
    void stop() override {
        isRunning = false;
    };

private:
    void run() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> sizeDistribution(1, 100);
        std::uniform_int_distribution<uint8_t> byteDistribution(0, 255);
        std::vector<uint8_t> data;
        while (isRunning) {
            size_t size = sizeDistribution(gen);
            if(data.size() != size) data.resize(size);
            for (auto &byte : data) byte = byteDistribution(gen);
    }
};
