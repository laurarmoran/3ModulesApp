//
// Created by laura on 7/05/25.
//

#include "../include/Generator_M1.h"

#include <iostream>
#include <random>

class IModule;

void Generator_M1::start(IModule* next) {
    try {
        isRunning = true;
        std::cout << "Starting Generator module...\n";
        thread = std::jthread([this, next](){ run(next); });
    } catch (const std::system_error& e) {
        std::cerr << "Error starting thread in Generator module: " << e.what() << std::endl;
        isRunning = false;
    }
}

void Generator_M1::stop() {
    isRunning = false;
}

void Generator_M1::run(IModule* next) {
    if (!next) {
        std::cerr << "[ ERR ] Next module is not set!" << std::endl;
        return;
    }
    std::random_device rd;
    std::uniform_int_distribution<int> sizeDistribution(1, 100);
    std::uniform_int_distribution<uint8_t> byteDistribution(0, 255);
    std::mt19937 gen(rd());
    std::vector<uint8_t> data;

    while (isRunning) {
        size_t size = sizeDistribution(gen);
        if(data.size() != size) data.resize(size);
        for (auto &byte : data) byte = byteDistribution(gen);
        if(next) next->receiveData(data);
    }
}

