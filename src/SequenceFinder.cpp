//
// Created by laura on 7/05/25.
//

#include "../include/SequenceFinder.h"

#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

class IModule;

void SequenceFinder::start(IModule *next) {
    try {
        isRunning = true;
        std::cout << "Starting SequenceFinder module...\n";
        thread = std::jthread([this, next](){ finder(next); });
    } catch (const std::system_error& e) {
        std::cerr << "Error starting thread in SequenceFinder: " << e.what() << std::endl;
        isRunning = false;
    }
}

void SequenceFinder::stop() {
    isRunning = false;
}

void SequenceFinder::receiveData(std::vector<uint8_t> &data) {
    if (data.empty()) {
        std::cerr << "[ WRN ] Received empty data" << std::endl;
        return;
    }
    try {
        std::lock_guard<std::mutex> lock(mtx);
        buffer.push_back(data);
        cv.notify_one();
    } catch (const std::exception& e) {
        std::cerr << "Error processing data in SequenceFinder module: " << e.what() << std::endl;
    }
}

void SequenceFinder::finder(IModule *next) {
    if (!next) {
        std::cerr << "[ ERR ] Next module is not set!" << std::endl;
        return;
    }
    while (isRunning) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&](){return !buffer.empty() || !isRunning;});
        std::vector<uint8_t> data = buffer.front();
        buffer.pop_front();
        if(std::ranges::search(data, byteMatch).begin() != data.end()) {
            if(next) next->receiveData(data);
        }
    }
}
