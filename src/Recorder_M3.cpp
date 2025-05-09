//
// Created by laura on 9/05/25.
//

#include "../include/Recorder_M3.h"

#include <iomanip>
#include <iostream>
#include <mutex>

void Recorder_M3::start(IModule *next) {
    try {
        isRunning = true;
        std::cout << "Starting Recorder module...\n";
        thread = std::jthread([this](){this->printer();});
    } catch (const std::system_error& e) {
        std::cerr << "Error starting thread in Recorder module: " << e.what() << std::endl;
        isRunning = false;
    }
}

void Recorder_M3::stop() {
    isRunning = false;
    cv.notify_all();
}

void Recorder_M3::receiveData(std::vector<uint8_t> &data) {
    std::unique_lock<std::mutex> lock(mtx);
    records.emplace_back(std::chrono::system_clock::now(), data);
    cv.notify_one();
}

void Recorder_M3::printer() {
    while (isRunning) {
        std::unique_lock<std::mutex> lock(mtx);
        try {
            cv.wait(lock, [&](){return !records.empty() || !isRunning;});
            for (auto & [timestamp, data] : records) {
                auto utc_time = std::chrono::system_clock::to_time_t(timestamp);
                std::cout << std::put_time(gmtime(&utc_time), "\n\n[ %Y-%m-%d %H:%M:%S UTC ]") << " : ";
                for (auto byte : data) std::cout << static_cast<int>(byte) << " | ";
            }
        } catch (const std::exception& e) {
            std::cerr << "Error processing data in Recorder module: " << e.what() << std::endl;
        }
    }
}
