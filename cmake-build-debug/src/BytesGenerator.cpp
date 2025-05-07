//
// Created by laura on 7/05/25.
//

#include "BytesGenerator.h"

#include <bits/random.h>

void BytesGenerator::start() {
    isRunning = true;
    thread = std::jthread([this](){run();});
}

void BytesGenerator::stop() {
    isRunning = false;
}

void BytesGenerator::setNextModule(IModule *next)  { nextModule = next; }

void BytesGenerator::run() const {
    std::random_device rd;
    std::uniform_int_distribution<int> sizeDistribution(1, 100);
    std::uniform_int_distribution<uint8_t> byteDistribution(0, 255);
    std::mt19937 gen(rd());
    std::vector<uint8_t> data;

    while (isRunning) {
        size_t size = sizeDistribution(gen);
        if(data.size() != size) data.resize(size);
        for (auto &byte : data) byte = byteDistribution(gen);

        //if(nextModule) nextModule.receiveData(data);
    }
}